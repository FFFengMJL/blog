import java.util.*;

public class Customer implements Runnable
{
  private BarberShop barberShop;
  private int customer;
  private int HAIRCUT_TIME = 5; // 剪发花费时间（等待时间）

  public Customer(int customer, BarberShop bShop)
  {
    this.customer = customer;
    this.barberShop = bShop;
  }

  public void run()
  {
    int sleepTime = (int =) (this.HAIRCUT_TIME * Math.random());
    System.out.println("Customer " + this.customer + "enter barber shop");
    int tmp = this.barberShop.getHairCut(this.customer); // 尝试剪发

    if (tmp == BarberShop.WAITED) // 如果阻塞
    {
      System.out.println("Customer " + this.customer + "waiting for haricut");;
    }
    else if (tmp == BarberShop.FULL) // 店满了
    {
      System.out.println("Customer " + this.customer + "cannot get haircut");
      return ;
    }
    else // 准备就绪，可以剪发
    {
      System.out.println("Customer " + this.customer + "start to haircut");
      SleepUtilities.nap(); // 剪发花费时间
      System.out.println("Customer " + this.customer + "leave barber shop");
      this.barberShop.leaveBarberShop(this.customer);
    }
  }
}