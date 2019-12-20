package Client;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client extends Thread {
    InetAddress host;
    int port;
    Socket socket;

    public Client(int port) throws IOException {
        this.host = null;
        this.socket = null;
        this.port = port;
    }

    public void run() {
        PrintWriter pr = null;
        try {
            this.socket = new Socket(InetAddress.getLocalHost().getHostName(), this.port);
            pr = new PrintWriter(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("Client->java Client");
        Scanner sc = new Scanner(System.in);
        System.out.print("->");
        String input = "";

        AcceptMsg accept = new AcceptMsg(this.socket);
        accept.start();
        while (!input.equals("exit")) {
            input = sc.nextLine();
            System.out.print("->");
            pr.write(input + '\n', 0, input.length() + 1);
            pr.flush();
        }
        pr.close();
        accept.interrupt();
    }
}
