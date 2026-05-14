class Solution {
public:
    // int recursion(vector<vector<int>> &dp, vector<int> &prices, int index, bool canPurchase){
    //     if(index>=prices.size()){
    //         return 0;
    //     }

    //     if(dp[index][canPurchase]!=-1) return dp[index][canPurchase];
    //     int profit = 0;
    //     if(canPurchase){
    //         int buy = -prices[index] + recursion(dp, prices, index+1, false);
    //         int skip = 0 + recursion(dp, prices, index+1, true);
    //         profit = max(buy, skip);
    //     } else {
    //         int sell = prices[index] + recursion(dp, prices, index+1, true);
    //         int skip = 0 + recursion(dp, prices, index+1, false);
    //         profit = max(sell, skip);
    //     }

    //     return dp[index][canPurchase] = profit;

    // }

    //     int recursion(vector<vector<int>> &dp, vector<int> &prices, int index, bool holding){
    //     if(index<0){
    //         return holding ? -1e9 : 0;
    //     }

    //     if(dp[index][holding]!=-1) return dp[index][holding];
    //     int profit = 0;
    //     if(holding){
    //          int buy = -prices[index] + recursion(dp, prices, index-1, false);
    //         int skip = 0 + recursion(dp, prices, index-1, true);
    //         profit = max(buy, skip);
           
           
    //     } else {
    //          int sell = prices[index] + recursion(dp, prices, index-1, true);
    //         int skip = 0 + recursion(dp, prices, index-1, false);
    //         profit = max(sell, skip);
    //     }

    //     return dp[index][holding] = profit;

    // }
    int maxProfit(vector<int>& prices) {
        // return recursion(dp, prices, prices.size()-1, false);
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        dp[0][1] = -1e9; 
        dp[0][0] = 0;
        for(int i = 1; i<=prices.size(); i++){
            dp[i][1] = max(-prices[i-1] + dp[i-1][0], 0 + dp[i-1][1]);
            dp[i][0] = max(prices[i-1] + dp[i-1][1], 0 + dp[i-1][0]);
        }

        return dp[prices.size()][0];
    }
};