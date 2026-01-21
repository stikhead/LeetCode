class Solution {
public:
    int recur(vector<int> &coins, vector<vector<int>> &dp, int amount, int n){
        if(amount==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        // if(n==1){
        //     if(amount%coins[n-1]==0){
        //         return amount/coins[n-1];
        //     }
        //     else {
        //         return INT_MAX - 1;
        //     }
        // }
        if(dp[n-1][amount]!=-1){
            return dp[n-1][amount];
        }
        if(coins[n-1]<=amount){
            return dp[n-1][amount] = recur(coins, dp, amount - coins[n-1], n) + recur(coins, dp, amount, n-1); 
        }
        else {
            return dp[n-1][amount] = recur(coins, dp, amount, n-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = recur(coins, dp, amount, coins.size());
        if(res == INT_MAX-1) return 0;
        return res;
    }
};