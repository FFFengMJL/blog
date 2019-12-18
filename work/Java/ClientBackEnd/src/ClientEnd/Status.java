package ClientEnd;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;

public class Status {
    private boolean bool = false;
    private JSONObject jsonObject = null;
    private JSONArray jsonArray = null;

    public Status(boolean bool) {
        this.bool = bool;
    }

    public Status(JSONArray jsonArray) {this.jsonArray = jsonArray;}
}
