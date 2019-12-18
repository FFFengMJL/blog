package Server;

import javax.swing.*;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerListener extends Thread {
    @Override
    public void run() {
        try {
            System.out.println("Initializing Port...");
            ServerSocket serverSocket = new ServerSocket(2333);
            System.out.println("Listening...");
            while (true) {
                Socket socket = serverSocket.accept();
                JOptionPane.showMessageDialog(null, "Connect to client!");
                ChatSocket cs = new ChatSocket(socket);
                cs.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
