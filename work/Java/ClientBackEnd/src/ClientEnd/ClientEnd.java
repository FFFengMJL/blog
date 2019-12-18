package ClientEnd;

import net.sf.jmimemagic.Magic;
import net.sf.jmimemagic.MagicMatch;
import okhttp3.*;
import com.alibaba.fastjson.*;
import org.jetbrains.annotations.NotNull;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class ClientEnd extends Thread {
    private static String url = "http://cloud.sysu.rwong.tech";
    private static final OkHttpClient client = new OkHttpClient();
    private static int port = 8080;

    public String getUrl() {return this.url;}
    public int getPort() {return this.port;}
    public OkHttpClient getClient() {return this.client;}

    public boolean signUp(String username, String password) throws Exception {
//        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
//        JSONObject json = new JSONObject();
//        json.put("username", username);
//        json.put("password", password);
//        Request request = new Request.Builder()
//                .url(this.url + ':' + this.port + "/user/sign_up")
//                .post(RequestBody.create(JSON, json.toString()))
//                .build();
//
//        Response response = client.newCall(request).execute();
//        if (!response.isSuccessful()) throw new IOException("Unexpected Code " + response);
//        System.out.println(response.code());
//        switch (response.code()) {
//            case 200: return true;
//            case 400: return false;
//            case 500: throw new IOException("后端错误");
//        }
//        return false;
        Boolean status = new Boolean(false);
        LogIn logIn = new LogIn(this, username, password,status);
        logIn.start();
        logIn.join();
        return status.booleanValue();
    }

    public boolean signIn(String username, String password, String email) throws Exception {
        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
        JSONObject json = new JSONObject();
        json.put("username", username);
        json.put("password", password);
        json.put("email", email);
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/user/sign_in")
                .post(RequestBody.create(JSON, json.toString()))
                .build();

        Response response = client.newCall(request).execute();
        if (!response.isSuccessful()) throw new IOException("Unexpected Code " + response);
        System.out.println(response.code());
        switch (response.code()) {
            case 200: return true;
            case 400: return false;
            case 500: throw new IOException("后端错误");
        }
        return false;
    }

    public JSONArray getFileList(String path) throws Exception {
        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/index/" + path)
                .build();
        Response response = client.newCall(request).execute();
        if (!response.isSuccessful()) throw new IOException("Unexpected Code " + response);
        return com.alibaba.fastjson.JSON.parseArray(response.body().string());
    }

    public JSONObject getFileDetails(int fileId) throws Exception {
        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/files/" + fileId)
                .build();
        Response response = client.newCall(request).execute();
        if (!response.isSuccessful()) throw new IOException("Unexpected Code " + response);
        return JSONObject.parseObject(response.body().string());
    }

    public boolean delFile(int fileId) throws Exception {
        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/files/" + fileId)
                .delete(new FormBody.Builder().build())
                .build();
        Response response = client.newCall(request).execute();
        if (!response.isSuccessful()) throw new IOException("Unexpected Code " + response);
        return response.code() == 200;
    }

    public void download(int fileId, Method method) throws Exception {
        Request request = new Request.Builder()
                .url(this.url + ':' + this.port + "/download/" + fileId)
                .build();
        client.newCall(request).enqueue(new Callback () {
            @Override
            public void onFailure(@NotNull Call call, @NotNull IOException e) {
                e.printStackTrace();
            }

            @Override
            public void onResponse(@NotNull Call call, @NotNull Response response) throws IOException {
                if (!response.isSuccessful()) throw new IOException("Unexpected code " + response);
                try {
                    method.invoke(JSONObject.parse(response.body().string()));
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (InvocationTargetException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public boolean upload(File file) throws Exception {
        try {
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
                public void onFailure(final Call call, final IOException e) {
                    // Handle the error
                }

                @Override
                public void onResponse(final Call call, final Response response) throws IOException {
                    if (!response.isSuccessful()) {
                        // Handle the error
                    }
                    // Upload successful
                }
            });

            return true;
        } catch (Exception ex) {
            // Handle the error
        }
        return false;
    }
}
