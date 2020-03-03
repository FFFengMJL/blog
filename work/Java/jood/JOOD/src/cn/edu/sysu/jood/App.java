package cn.edu.sysu.jood;

/**
 * Main entry of JoodApp
 */
public class App {
    public static void main(String[] args) {
        try {
            Configuration cfg = Configuration.ParseArgs(args);
            Client client = (Client) Class.forName(cfg.client).getDeclaredConstructor().newInstance();
            client.Init(cfg);
            client.Run();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}