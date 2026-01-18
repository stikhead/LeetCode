class Solution {
  public:
    int recur(vector<int>& arr, vector<vector<int>> &dp, int target, int n){
        if(target==0 && n==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n-1][target]!=-1){
            return dp[n-1][target];
        }
        if(arr[n-1]<=target){
            return dp[n-1][target] = recur(arr, dp, target, n-1) + recur(arr, dp, target - arr[n-1], n-1);
        }
        else {
            return dp[n-1][target] = recur(arr, dp, target, n-1);
        }
        
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int size = arr.size();
        vector<vector<int>> dp(size, vector<int>(target+1, -1));
        return recur(arr, dp, target, arr.size());
    }
};