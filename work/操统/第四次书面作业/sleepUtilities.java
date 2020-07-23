public class SleepUtilities
{
  private static final int NAP_TIME = 5;

  public static void nap()
  {
    nap(NAP_TIME);
  }

  public static void nap(int duration)
  {
    int sleepTime = (int) (NAP_TIME * Math.random());
    try 
    {
      Thread.sleep(sleepTime * 1000);
    }
    catch (InterruptedException err)
    {}
  }
}