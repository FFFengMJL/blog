package Client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.net.Socket;

public class AcceptMsg extends Thread {
    private Socket socket;

    public AcceptMsg(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        String output = null;
        BufferedReader bReader = null;
        try {
            bReader = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream(), "UTF-8"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        while (true) {
            try {
                if ((output = bReader.readLine()) != null) {
                    System.out.println("Recevied: " + output);
                    System.out.print("->");
                }
                Thread.sleep(10);
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
                return;
            }
        }
    }
}
