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
        // vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        // return recursion(dp, coins, coins.size()-1, amount);
        vector<vector<unsigned int>> dp(coins.size()+1, vector<unsigned int>(amount+1, 0));
        for(int i=0; i<=coins.size(); i++){
            dp[i][0] = 1;
        }

        for(int i=0; i<=amount; i++){
            dp[0][i] = 0;
        }

        for(int i=1; i<=coins.size(); i++){
            for(int j=1; j<=amount; j++){
                   if(j < coins[i-1]){
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                }
            }
        }
        return (int)dp[coins.size()][amount];
    }
};