class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<int>&coins, int index, int amount){
        if(amount==0) return 1;
        if(index<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int left = 0;
        if(amount-coins[index]>= 0) left = recursion(dp, coins, index, amount-coins[index]);
        
        int right = recursion(dp, coins, index-1, amount);
        return dp[index][amount] = left+right;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return recursion(dp, coins, coins.size()-1, amount);
    }
};