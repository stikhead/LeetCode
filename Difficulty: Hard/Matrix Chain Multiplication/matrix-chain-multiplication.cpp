class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &arr, int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            int temp = recursion(dp, arr, i, k) + recursion(dp, arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size(), -1));
        return recursion(dp, arr, 1, arr.size()-1);
    }
};