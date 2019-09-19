import java.util.Collections;
import java.util.Vector;

public class StockSeller {
    private int [] prices;

    public StockSeller(int [] prices) {
        this.prices = prices;
    }

    public int MaxProfit1() {
        int min_index = 0;
        int res = 0;
        for (int i = 0; i < this.prices.length; i++) {
            if (this.prices[i] < this.prices[min_index]) min_index = i;
            else res = Math.max(res, this.prices[i] - this.prices[min_index]);
        }
        return res;
    }

    public int MaxProfit2() {
        int res = 0;
        for (int i = 1; i < this.prices.length; i++)
            if (this.prices[i] > this.prices[i - 1]) res += this.prices[i] - this.prices[i - 1];
        return res;
    }

    public int MaxProfit3() {
        Vector<Integer> res = new Vector<Integer>();
        res.add(0);
        int temp = 0;
        for (int i = 1; i < this.prices.length; i++) {
            if (this.prices[i - 1] > this.prices[i]) {
                res.add(temp);
                temp = 0;
            }
            else temp += this.prices[i] - this.prices[i - 1];
        }
        res.add(temp);
        res.sort(Collections.reverseOrder());
        return res.elementAt(0) + res.elementAt(1);
    }
}
//        Prices: An Integer Array, the ith number means the stock price of the ith day.
//         StockSeller：The constructor, in which initiates the stock prices.
//         MaxProfit1：Design an algorithm to find the maximum profit, only permitted to complete at
//        most one transaction. Note that you cannot sell a stock before you buy.
