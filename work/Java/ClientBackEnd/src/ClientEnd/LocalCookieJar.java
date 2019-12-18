package ClientEnd;

import okhttp3.*;
import java.util.ArrayList;
import java.util.List;

//拦截cookie
class LocalCookieJar implements CookieJar {
    List<Cookie> cookies;


    @Override
    public List<Cookie> loadForRequest(HttpUrl url) {
        if (cookies != null)
            return cookies;
        return new ArrayList<Cookie>();
    }

    @Override
    public void saveFromResponse(HttpUrl url, List<Cookie> cookies) {
        this.cookies = cookies;
        //存储当前cookie,用于webview中同步cookie
//        CookiesManager.getInstance().cookieMap.put(url,cookies);
    }

}