package Server;

import javax.swing.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerListener extends Thread {
    @Override
    public void run() {
        try {
            System.out.println("Server->java Server");
            System.out.println("Initializing Port...");
            ServerSocket serverSocket = new ServerSocket(2333);
            System.out.println("Listening...");
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Connect to client!");
                ChatSocket cs = new ChatSocket(socket);
                cs.start();
                ChatManager.getChatManager().add(cs);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
    }
}
