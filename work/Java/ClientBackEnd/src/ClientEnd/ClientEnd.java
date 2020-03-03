package ClientEnd;

import net.sf.jmimemagic.Magic;
import net.sf.jmimemagic.MagicMatch;
import okhttp3.*;
import com.alibaba.fastjson.*;
import org.jetbrains.annotations.NotNull;

import java.io.File;
import java.io.IOException;

public class ClientEnd extends Thread {
    private static String url = "http://cloud.sysu.rwong.tech";
    private static final OkHttpClient client = new OkHttpClient();
    private static int port = 8080;

    public String getUrl() {return this.url;}
    public int getPort() {return this.port;}
    public OkHttpClient getClient() {return this.client;}

    public void logOut(CallBackFunc callBackFunc) throws Exception {
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/user/log_out")
                .post(RequestBody.create(MediaType.parse("application/json"), ""))
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                try {
                    System.out.println(response.code());
                    callBackFunc.done(new CallBackFunArg(true, null, null));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

    }

    public void signIn(String username, String password, CallBackFunc callBackFunc) throws Exception {
        final MediaType JSON = MediaType.parse("application/json");
        JSONObject json = new JSONObject();
        json.put("username", username);
        json.put("password", password);
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/user/sign_in")
                .post(RequestBody.create(JSON, json.toString()))
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                switch (response.code()) {
                    case 200:
                        try {
                            callBackFunc.done(new CallBackFunArg(true, null, null));
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        break;
                    case 400:
                        try {
                            callBackFunc.done(new CallBackFunArg(false, null, null));
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        break;
                    case 500: throw new IOException("后端错误");
                    default: throw new IOException("我也不知道什么问题: " + response.code());
                }
            }
        });

    }

    public void signUp(String username, String password, String email, String name, CallBackFunc callBackFunc) throws Exception {
        final MediaType JSON = MediaType.parse("application/json");
        JSONObject json = new JSONObject();
        json.put("username", username);
        json.put("password", password);
        json.put("email", email);
        json.put("name", name);
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/user/sign_up")
                .post(RequestBody.create(JSON, json.toString()))
                .build();
        System.out.println("准备注册");
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                switch (response.code()) {
                    case 200:
                        try {
                            callBackFunc.done(new CallBackFunArg(true, null, null));
                        } catch (Exception e) {
                            e.printStackTrace();
                        } break;
                    case 400:
                        try {
                            callBackFunc.done(new CallBackFunArg(false, null, null));
                        } catch (Exception e) {
                            e.printStackTrace();
                        } break;
                    case 500: throw new IOException(("后端错误"));
                    default: throw new IOException("我也不知道什么问题: " + response.code());
                }
            }
        });

    }

    public void getFileList(String path, CallBackFunc callBackFunc) throws Exception {
        final MediaType JSON = MediaType.parse("application/json");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/index/" + path)
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                try {
                    callBackFunc.done(new CallBackFunArg(true, null, com.alibaba.fastjson.JSON.parseArray(response.body().string())));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

    }

    public void getFileDetails(int fileId, CallBackFunc callBackFunc) throws Exception {
        final MediaType JSON = MediaType.parse("application/json");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/files/" + fileId)
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                try {
                    callBackFunc.done(new CallBackFunArg(false, JSONObject.parseObject(response.body().string()), null));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public void delFile(int fileId, CallBackFunc callBackFunc) throws Exception {
        final MediaType JSON = MediaType.parse("application/json");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/files/" + fileId)
                .delete(new FormBody.Builder().build())
                .build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                try {
                    callBackFunc.done(new CallBackFunArg(response.code() == 200, null, null));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });

    }

    public void download(int fileId, CallBackFunc callBackFunc) throws Exception {
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/download/" + fileId)
                .build();
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                try {
                    callBackFunc.done(new CallBackFunArg(false, null, JSON.parseArray(response.body().string())));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public void upload(File file, CallBackFunc callBackFunc) throws Exception {
            Magic parser = new Magic();
            MagicMatch match = parser.getMagicMatch(file, false);
            String fileType = match.getMimeType() ;

            RequestBody requestBody = new MultipartBody.Builder().setType(MultipartBody.FORM)
                    .addFormDataPart("file", file.getName(),
                            RequestBody.create(MediaType.parse(fileType), file))
                    .addFormDataPart("some-field", "some-value")
                    .build();

            Request request = new Request.Builder()
                    .url(this.url + ':' + this.port + "/files/")
                    .post(requestBody)
                    .build();

            client.newCall(request).enqueue(new Callback() {
                @Override
                public void onFailure(@NotNull Call call, @NotNull IOException e) {
                    e.printStackTrace();
                }

                @Override
                public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                    try {
                        callBackFunc.done(new CallBackFunArg(true, null, null));
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            });

    }
}
