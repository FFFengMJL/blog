package Thread;

class ThreadM extends Thread {
    public void run() {
        try {
              for (int i = 0; i < 5; i++) {
                    Thread.sleep(1000);
                    System.out.println("ThreadM");
              }
        }
        catch (InterruptedException ex) {
            ex.printStackTrace();
        }
    }
}

