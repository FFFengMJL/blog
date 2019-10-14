import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner x=new Scanner(System.in);
        while(x.hasNext()){
            int m=x.nextInt();
            int[] price = new int[m];
            for(int i=0;i<m;i++)
                price[i]=x.nextInt();
            StockSeller stock_seller = new StockSeller(price);
            System.out.println(stock_seller.MaxProfit1());
            System.out.println(stock_seller.MaxProfit2());
            System.out.println(stock_seller.MaxProfit3());
        }
        x.close();
    }
}
//        Prices: An Integer Array, the ith number means the stock price of the ith day.
//         StockSeller：The constructor, in which initiates the stock prices.
//         MaxProfit1：Design an algorithm to find the maximum profit, only permitted to complete at
//        most one transaction. Note that you cannot sell a stock before you buy.
