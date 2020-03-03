package Server;

import java.io.*;
import java.net.Socket;

public class ChatSocket  extends Thread{
    Socket socket;

    public ChatSocket(Socket socket) {
        this.socket = socket;
    }

    // send Message
    public void sendMessage(String message) {
        try {
            socket.getOutputStream().write(message.getBytes("UTF-8"));
//            PrintWriter pr = new PrintWriter(socket.getOutputStream());
//            pr.write(message, 0, message.length() + 1);
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }

    public void run() {
        try {
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(socket.getInputStream(), "UTF-8")
            );
            String input = null;
            while ((input = br.readLine()) != null) {
                ChatManager.getChatManager().publish(this, input);
                System.out.println(input);
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }
}
