class Solution {
  public:
 // dp iterative
      bool isSubsetSum(vector<int>& arr, int sum) {
        int size = arr.size();
        vector<vector<bool>> dp(size+1, vector<bool>(sum+1));
        for(int j=0; j<sum+1; j++){
            dp[0][j] = false;
        }
        for(int j=0; j<size+1; j++){
            dp[j][0] = true;
        }
        for(int i=1; i<size+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size][sum];
    }
    
    //memoization
    //   bool dpSol(vector<int>& arr, vector<vector<int>> &dp, int sum, int n){
    //       if(sum==0){
    //           return true;
    //       }
    //       if(n==0){
    //           return false;
    //       }
    //       if(dp[n-1][sum]!=-1){
    //           return dp[n-1][sum];
    //       }
    //       if(arr[n-1]<=sum){
    //           return dp[n-1][sum] = dpSol(arr, dp, sum - arr[n-1], n-1) || dpSol(arr, dp, sum, n-1);
    //     }
    //     else {
    //         return dp[n-1][sum] = dpSol(arr, dp, sum, n-1);
    //     }
          
    //   }
    //   bool isSubsetSum(vector<int>& arr, int sum) {
    //     int size = arr.size();
    //     vector<vector<int>> dp(size, vector<int>(sum+1, -1)); 
    //     return dpSol(arr, dp, sum, size);
    // }
    
    // recursion 
    // bool recur(vector<int>& arr, int sum, int n){
    //     if(sum == 0){
    //         return true;
    //     }
    //     if(n==0){
    //         return false;
    //     }
    //     if(arr[n-1]<=sum){
    //         return recur(arr, sum - arr[n-1], n-1) || recur(arr, sum, n-1);
    //     }
    //     else {
    //         return recur(arr, sum, n-1);
    //     }
    // }
    // bool isSubsetSum(vector<int>& arr, int sum) {
    //     // vector<vector<int>> dp(arr.size(), vector<int>(sum+1)) 
    //     int size = arr.size();
    //     return recur(arr, sum, size);
    // }
};