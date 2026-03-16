class Solution {
    public int maxProfit(int[] prices) {
        int mincostprice = prices[0];
        int maxprofit = 0;
        for(int i = 1; i < prices.length; i ++){
            maxprofit = Math.max(maxprofit, prices[i] - mincostprice);
            if(prices[i] < mincostprice){
                mincostprice = prices[i];
            }
        }
        return maxprofit;
    }
}