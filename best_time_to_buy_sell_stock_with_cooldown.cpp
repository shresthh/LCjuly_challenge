class Solution {
public:
    // dp[len][2]
    //case 1: we have a stock on day i , dp[i][1](buy)
        //1. we buy it today
           // dp[i-2][0] -price[i]
    
        //2. we are carry forwarding the previous one.
           //  dp[i-1][1]           
    
    //case 2: we dont have a stock on day i, dp[i][0] (sell)
      //1. we sell it today
            //  dp[i-1][1] + prices[i]   
    
        //2. we are carry forwarding it to sell in future.
            //  dp[i-1][0]  
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
       
        if(len <= 1)
            return 0;
        if(len == 2 && prices[0] > prices[1])
            return 0;
       else if(len == 2 && prices[0] < prices[1])
            return prices[1] - prices[0];
        int dp[len][2];
        dp[0][1] = -prices[0];
        dp[0][0] = 0;
        dp[1][1] = max(dp[0][1], dp[0][0] - prices[1]);
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        for (int i = 2; i< len; i++){
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-2][0]-prices[i],dp[i-1][1]);
        }
        return dp[len-1][0];
    }
};
