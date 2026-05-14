class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<int> &prices, int index, bool canPurchase){
        if(index>=prices.size()){
            return 0;
        }

        if(dp[index][canPurchase]!=-1) return dp[index][canPurchase];
        int profit = 0;
        if(canPurchase){
            int buy = -prices[index] + recursion(dp, prices, index+1, false);
            int skip = 0 + recursion(dp, prices, index+1, true);
            profit = max(buy, skip);
        } else {
            int sell = prices[index] + recursion(dp, prices, index+1, true);
            int skip = 0 + recursion(dp, prices, index+1, false);
            profit = max(sell, skip);
        }

        return dp[index][canPurchase] = profit;

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(3, -1));
        return recursion(dp, prices, 0, true);
    }
};