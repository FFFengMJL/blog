package MultiThread;
public class Producer implements Runnable{

    private Thread t;
    public int name;
    private static int content = 0;
    public static Object lock;

    public Producer(int name) {
        this.name = name;
        lock = new Object();
    }


    @Override
    public void run() {}
    public synchronized void Get(Customer customer) {
        while (true) {
            for (int i = 0; i < 10; i++) {
                synchronized (lock) {
                    if (content == 0) {
                        System.out.println("Set " + name + "-> Item1 : 12345");
                        content = 1;
                    }
                    else {
                        System.out.println("Set " + name + "-> Item2 : abcde");
                        content = 0;
                    }
                    name++;
                    customer.Set(this);
                }
                try {
                    Thread.sleep(1);
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
            return;
        }
    }

    public void start() {
        if (t == null) {
            t = new Thread(this);
            t.start();
        }
    }
}

/*TODO
 *   Method run that produces content.
 *   The Producer needs to use run method to produce 10 content,
 *   “12345” for odd iteration,
 *   “abcde” for even.
 *   And only the Customer consumes the last content,
 *   the producer can produce a new one.*/
