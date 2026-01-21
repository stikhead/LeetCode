class Solution {
  public:
    int recur(vector<int>&coins, vector<vector<int>> &dp, int sum, int n){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n-1][sum]!=-1){
            return dp[n-1][sum];
        }
        if(coins[n-1]<=sum){
            return dp[n-1][sum] = recur(coins, dp, sum-coins[n-1], n) + recur(coins, dp, sum, n-1); 
        }
        else {
            return dp[n-1][sum] = recur(coins, dp, sum, n-1);
        }
    }
    int count(vector<int>& coins, int sum) {
        int size =  coins.size();
        vector<vector<int>> dp(size, vector<int>(sum+1, -1));
        return recur(coins, dp, sum, size);
    }
};