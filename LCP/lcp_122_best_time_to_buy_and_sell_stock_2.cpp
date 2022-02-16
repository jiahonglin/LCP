class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*Method 1*/
        /*
        int profit=0;
        for(int i=1;i<prices.size();i++){
            profit+=max(prices[i]-prices[i-1],0);
        }
        return profit;
        */
        /*Method 2*/
        if(prices.size()==1) return 0;
        if(prices.size()==2) return prices[1]-prices[0]<0?0:prices[1]-prices[0];
        vector<int> dp(prices.size(),0);
        int profit=0;
        dp[0] = prices[0];
        dp[1] = prices[1];
        int stockCost = min(prices[0],prices[1]);
        for(int i=2;i<prices.size();i++){
            if(prices[i] > dp[i-1]){
                dp[i] = prices[i];
            }
            else{
                profit+=dp[i-1]-stockCost;
                stockCost=prices[i];
                dp[i] = prices[i];
            }
            if(i == prices.size()-1 && prices[i]>=dp[i-1]){
                profit+=prices[i]-stockCost;
            }
        }
        return profit;
    }
};
