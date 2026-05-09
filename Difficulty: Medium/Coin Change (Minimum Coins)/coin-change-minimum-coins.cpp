class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &coins, int sum, int index){
            if(sum==0) return 0;
            if(sum<0) return -1;
        
        if(index<0){
            return 1e9;
        } 
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        int left = 1e9;
        if(sum-coins[index]>=0){
            left = 1+recursion(dp, coins, sum-coins[index], index);
            
        }
        
        int right = recursion(dp, coins, sum, index-1);
        return dp[index][sum] = min(left, right);
    }
    int minCoins(vector<int> &coins, int sum) {
        vector<vector<int>> dp(coins.size(), vector<int>(sum+1, -1));
        int output = recursion(dp, coins, sum, coins.size()-1);
        return output == 1e9 ? -1 : output;
        
    }
};