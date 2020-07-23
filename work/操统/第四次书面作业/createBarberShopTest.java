public class CreateBarberShopTest implements Runnable
{
  static final private int WAIT_TIME = 3;
  static public void main(String [] args)
  {
    new Thread(new CreateBarberShopTest()).start();
  }

  public void run()
  {
    BarberShop newShop = new BarberShop(15);
    int customer = 1;

    while (customer <= 10000)
    {
      new Thread(new Customer(customer, newShop)).start();
      customer++;
    }
  }
}