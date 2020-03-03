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
        if (this.prices.length == 0) {
            return 0;
        }
        int dp1 = 0;
        int dp2 = 0;
        int min1 = this.prices[0];
        int min2 = this.prices[0];
        for (int i = 1; i < this.prices.length; i++) {
            min1 = Math.min(this.prices[i] - 0, min1);
            dp1 = Math.max(dp1, this.prices[i] - min1);

            min2 = Math.min(this.prices[i] - dp1, min2);
            dp2 = Math.max(dp2, this.prices[i] - min2);
        }
        return dp2;
    }
}
