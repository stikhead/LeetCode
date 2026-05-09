class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &coins, int sum, int index){
        if(sum==0){
            return 1;
        }
        
        if(index<0){
            return 0;
        }
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        int left = 0;
        if(sum-coins[index]>=0){
            left = recursion(dp, coins, sum-coins[index], index);
        }
        
        int right = recursion(dp, coins, sum, index-1);
        
        return dp[index][sum] = left+right;
    }
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, -1));
        return recursion(dp, coins, sum, coins.size()-1);
    }
};