class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &arr, int target, int sum, int index){
       
        if(sum>target){
            return 0;
        }
       if(index == arr.size()){
            if(sum == target) return 1;
            else return 0;
        }
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        
        return dp[index][sum] = recursion(dp, arr, target, sum+arr[index], index+1) + recursion(dp, arr, target, sum, index + 1);
    }
    int perfectSum(vector<int>& arr, int target) {
        // if(arr.size()==1){
        //     if(arr[0]==target) return 1;
        //     else return 0;
        // }
        
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        return recursion(dp, arr, target, 0, 0);
        
    }
};