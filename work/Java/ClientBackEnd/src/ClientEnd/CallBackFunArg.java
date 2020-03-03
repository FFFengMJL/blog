package ClientEnd;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;

public class CallBackFunArg {
    public boolean bool;
    public JSONArray jsonArray;
    public JSONObject jsonObject;

    public CallBackFunArg() {
        bool = false;
        jsonArray = null;
        jsonObject = null;
    }

    public CallBackFunArg(boolean bool, JSONObject jsonObject, JSONArray jsonArray) {
        this.bool = bool;
        this.jsonObject = jsonObject == null ? null : (JSONObject) jsonObject.clone();
        this.jsonArray = jsonArray == null ? null : (JSONArray) jsonArray.clone();
    }
}
