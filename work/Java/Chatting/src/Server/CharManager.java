package Server;

import java.util.Vector;

class ChatManager {
    private ChatManager(){}
    private static final ChatManager CM=new ChatManager();
    public static ChatManager getChatManager(){
        return CM;
    }

    Vector<ChatSocket> vector = new Vector<ChatSocket>();
    public void add(ChatSocket cs){
        vector.add(cs);
    }

    /*send message to another Client
     *ChatSocket cs： 调用publish的线程
     *msg：message want to be sent */
    public void publish(ChatSocket cs, String msg){
        for (int i = 0; i < vector.size(); i++) {
            ChatSocket csTemp = vector.get(i);
            if (!cs.equals(csTemp)) csTemp.sendMessage(msg+"\n");//不用发送给自己。
        }
//        System.out.println(msg);
    }
}