class Solution {
    public:

    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        if(prices.size()==2) return (prices[1]-prices[0]>0?(prices[1]-prices[0]):0);
        vector<int> buy(prices.size(),0);
        vector<int> sell(prices.size(),0);
        buy[0] = -1 * prices[0];
        buy[1] = -1 * (prices[0]<prices[1]?prices[0]:prices[1]);
        sell[0] = 0;
        sell[1] = (prices[1]-prices[0]>0?(prices[1]-prices[0]):0);
        for(int i=2;i<prices.size();i++){
            buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
        }
        return max(buy.back(),sell.back());
    }
/*
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
*/
};
