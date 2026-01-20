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
        vector<vector<int>> dp(size+1, vector<int>(target+1));
        dp[0][0] = 1;
        for(int i=1; i<size+1; i++){
            for(int j=0; j<target+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size][target];
    }
};