// User function Template for C++

class Solution {
  public:
    int recur(vector<int> &price,  vector<vector<int>>& dp, vector<int> &length, int cap, int n){
        if(cap==0){
            return 0;
        }
        if(n==0){
            return 0;
        }
        if(dp[n-1][cap]!=-1){
            return dp[n-1][cap];
        }
        if(length[n-1]<=cap){
            return dp[n-1][cap] = max(price[n-1] + recur(price,dp,  length, cap - length[n-1] , n), recur(price, dp, length, cap , n-1));
        }
        else {
           return dp[n-1][cap]=recur(price,dp,  length, cap , n-1);
        }
    }
    int cutRod(vector<int> &price) {
        int size = price.size();
        vector<int> length;
        vector<vector<int>> dp(size, vector<int>(size+1, -1));
        for(int i=1; i<=size; i++){
            length.push_back(i);
        }
        return recur(price,dp, length, size, size);
    }
};