class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<int>&coins, int index, int amount){
        if(amount==0) return 0;
        if(index<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int left = INT_MAX;
        if(amount-coins[index]>=0) left = 1 + recursion(dp, coins, index, amount-coins[index]);
        
        int right = recursion(dp, coins, index-1, amount);
        return dp[index][amount] = min(left,right);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int sol = recursion(dp, coins, coins.size()-1, amount);
        return sol!=1e9 ? sol : -1;
    }
};