public class BarberShop
{
  private int chairNum;
  private int barber;
  private int chairState[];

  // 使用静态变量来表示状态
  static final int FULL = -1;
  static final int EMPTY = 0;
  static final int OCUPIED = 1;
  static final int SLEEPING = 2;
  static final int DONE = 3;
  static final int WAITED = 4;

  // 初始化
  public BarberShop(int chairNum)
  {
    this.chairNum = chairNum;
    this.chairState = new int[chairNum];
    this.barber = SLEEPING;

    for (int i = 0; i < this.chairNum; i++)
      this.chairState[i] = EMPTY;
  }

  // 找椅子
  private boolean findChair(int customer)
  {
    int tmp = getFirstEmptyChair();
    if (tmp == FULL) // 如果彻底满了
      return false;
    else             // 如果有位置
      this.chairState[tmp] = OCUPIED; // 占这个位置
  }

  public synchronized int getHairCut(int customer)
  {
    if (this.barber == SLEEPING) // 如果在休眠
    {
      this.barber = OCUPIED;
      return SLEEPING;
    }
    else if (this.barber == OCUPIED) // 如果拥塞
    {
      boolean tmp = findChair(customer);
      if (!tmp) // 人满
        return FULL;
      else
      {
        while(this.barber == OCUPIED) // 当处于拥挤的情况下，等待
        {
          try
          {
            this.wait();
          }
          catch(InterruptedException err)
          {}
        }

        for (int i = 0; i < this.chairNum; i++)
        {
          if (this.chairState[i] == OCUPIED) // 位置准备释放
          {
            this.chairState[i] = EMPTY;
            break;
          }
        }

        this.barber = OCUPIED;
        return WAITED;
      }
    }
    else
    {
      this.barber = OCUPIED;
      return DONE;
    }
  }

  public synchronized void leaveBarberShop(int customer)
  {
    boolean tmp = isAnyoneWaiting(); // 是否有人在等待
    if (tmp == true)
      this.barber = DONE;
    else
      this.barber = SLEEPING;

    notify();
  }

  private int getFirstEmptyChair()
  {
    // 循环找位置
    for (int i = 0; i < this.chairNum; i++)
    {
      if (this.chairState[i] == EMPTY)
        return i;
    }

    return FULL;
  }

  // 查看是否有人在等待 == 是否有位置被占用
  private boolean isAnyoneWaiting()
  {
    for (int i = 0; i < this.chairNum; i++)
    {
      if (this.chairState[i] == OCUPIED);
        return true;
    }
    return false;
  }
}