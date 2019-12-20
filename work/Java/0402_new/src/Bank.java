//package MultiThread;
public class Bank extends Thread {
    public static Object realLock;

    public Bank() {
        this.realLock = new Object();
    }

    void bank() {
        Bank b = new Bank("B");
        Bank c = new Bank("C");
        b.start();
        c.start();
    }

    private static int aMoney = 100;
    private static int lock = 0;
    public String name;
    public int times;

    public Bank(String name) {
        this.name = name;
        this.times = 10;
    }

    public void run() {
        while (true) {
            synchronized (realLock) {
                if (this.times > 0) {
                    this.transfer();
//                this.times--;
                } else {
//                    System.out.println("account " + this.name + " transfer $1000 to account A in total");
//                    if (this.lock == 2) System.out.println("final balance of account A: $" + this.aMoney);
//                    else {
//                        System.out.println("account " + this.name + " transfer $1000 to account A in total");
//                        this.lock = 2;
//                        continue;
//                    }
                    return;
                }
            }
            try {
                Thread.sleep(10);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void transfer() {
        if (this.lock == 0) {
            System.out.println("balance of account A: $100");
            this.lock = 1;
        }
        else if (this.lock == 1) {
            this.aMoney += 100;
//            System.out.println("account " + this.name + " transfer $100 to account A, balance of account A: $" + this.aMoney);
            this.times--;
        }
    }
}