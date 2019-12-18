package Server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.InputStreamReader;
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
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(socket.getInputStream(), "UTF-8")
            );
            while (br.readLine() != null) {
                System.out.println(br.readLine());
                ChatManager.getChatManager().publish(this,                                                                                                br.readLine());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
