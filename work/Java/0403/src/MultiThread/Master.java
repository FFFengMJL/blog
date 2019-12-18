package MultiThread;
public class Master{
    public void master() {
        Producer a = new Producer(1);
        Customer b = new Customer(1);
        Thread c = new Thread(new Runnable() {
            @Override
            public void run() {
                a.Get(b);
            }
        });
        c.start();
    }
}