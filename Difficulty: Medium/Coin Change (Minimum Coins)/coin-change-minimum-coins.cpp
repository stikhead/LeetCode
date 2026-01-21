class Solution {
  public:
    int recur(vector<int>&coins, vector<vector<int>> &dp, int sum, int n){
        if(sum==0){
            return 0;
        }
        if(n==0){
            return INT_MAX-1;
        }
        if(n==1){
            if(sum%coins[n-1]!=0){
                return INT_MAX-1;
            }        
            else {
                return sum/coins[n-1];
            }
        }
        if(dp[n-1][sum]!=-1){
            return dp[n-1][sum];
        }
        if(coins[n-1]<=sum){
            return dp[n-1][sum] = min(1 + recur(coins, dp, sum - coins[n-1], n), recur(coins, dp, sum, n-1));
        }
        else {
            return dp[n-1][sum] = recur(coins, dp, sum, n-1);
        }
        
    }
    int minCoins(vector<int> &coins, int sum) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(sum+1, -1));
        int res = recur(coins, dp, sum, coins.size());
        if(res==INT_MAX - 1) return -1;
        return res;
    }
};