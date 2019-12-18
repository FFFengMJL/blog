package ClientEnd;

import java.io.IOException;

public class Main {
    public static void main(String[] args) throws Exception {
        ClientEnd test = new ClientEnd();
        try {
            System.out.println(test.signUp("mijialong", "12346"));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
