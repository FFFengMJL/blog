package MultiThread;
public class Customer implements Runnable{


    private static int content = 0;
    public int name;
    public static Object lock;
    private Thread t;

    public Customer(int name) {
        this.name = name;
        lock = new Object();
    }

    @Override
    public void run() {
    }

    public void Set(Producer tar) {
//        while (true) {
//            for (int i = 0; i < 10; i++) {
                synchronized (lock) {
                    if (content == 0) {
                        System.out.println("Get " + name + "-> Item1 : 12345");
                        content = 1;
                    } else {
                        System.out.println("Get " + name + "-> Item2 : abcde");
                        content = 0;
                    }
                    name++;
                    try {
                        Thread.sleep(1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
//                }
//            }
//            return;
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
 *  Method run that consumes content.
 *  The producer needs to use run method to consume 10 contents,
 *  and the Customer can only consumes the last produced content.*/
