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
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // int sol = recursion(dp, coins, coins.size()-1, amount);
        // return sol!=1e9 ? sol : -1;

        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 1e9));
        for(int i=0; i<=coins.size(); i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=coins.size(); i++){
            for(int j=1; j<=amount; j++){
                if(j<coins[i-1]){
                    dp[i][j]  = dp[i-1][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i-1]]);
                }
            }
        }
           return dp[coins.size()][amount] >= 1e9 ? -1 : dp[coins.size()][amount];
    }
};