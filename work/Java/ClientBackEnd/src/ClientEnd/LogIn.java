package ClientEnd;

import com.alibaba.fastjson.JSONObject;
import okhttp3.*;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class LogIn extends Thread{
    private ClientEnd client;
    private String username;
    private String password;
    public Boolean status;
    public Method method;
    public Callback callback;

    public LogIn(ClientEnd client, String username, String password, Boolean status) {
        this.client = client;
        this.username = username;
        this.password = password;
        this.status = status;
//        this.method = method;
    }

    @Override
    public void run() {
        final MediaType JSON = MediaType.parse("application/json; charset=utf-8");
        JSONObject json = new JSONObject();
        json.put("username", username);
        json.put("password", password);
        Request request = new Request.Builder()
                .url(this.client.getUrl() + ':' + this.client.getPort() + "/user/sign_up")
                .post(RequestBody.create(JSON, json.toString()))
                .build();

        Response response = null;
        try {
            response = this.client.getClient().newCall(request).execute();
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (!response.isSuccessful()) try {
            throw new IOException("Unexpected Code " + response);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println(response.code());
        switch (response.code()) {
            case 200: this.status; break;
            case 400: this.status = false; break;
            case 500:
                try {
                    throw new IOException("后端错误");
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
        System.out.println(this.status.booleanValue());
    }
}
