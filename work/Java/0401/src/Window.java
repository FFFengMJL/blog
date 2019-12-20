public class Window extends Thread {
    public static int time = 1;
    public static Object lock = 15;
    public String name;

    public Window() {}

    public Window(String name) {
        this.name = name;
        this.lock = new Object();
    }

    void window() {
        Thread t1 = new Thread(this, "Window1");
        Thread t2 = new Thread(this, "Window2");
        Thread t3 = new Thread(this, "Window3");
        t1.start();
        t2.start();
        t3.start();
    }

    public void run() {
        while (true) {
            synchronized (lock) {
                if (this.time <= 20) System.out.println(Thread.currentThread().getName() + ": ticket" + this.time++);
                else if (this.time == 21){
                    System.out.println("Sold Out");
                    this.time++;
                }
                else return;
            }
            try {
                Thread.sleep(1);
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

//    public synchronized void sale() {
//        if (this.time <= 20) System.out.println(Thread.currentThread().getName() + ": ticket" + this.time++);
//        else if (this.lock == 15) {
//            System.out.println("Sold Out");
//            lock--;
//        }
//        else System.out.println("Sold Out");
//    }
//        while (this.time < 20) {
//            this.time++;
//            System.out.println("Window" + Thread.currentThread().getName().charAt(Thread.currentThread().getName().length() - 1) + ": ticket" + this.time);
//        }
}