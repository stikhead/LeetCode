class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &arr, int target, int sum, int index){
       
    
       if(index < 0){
           if(sum==target){
                return 1;
            }
            return 0;
       }
       if(sum>target){
            return 0;
        }
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        int pick = 0;
        if(sum+arr[index]<=target){
             pick = recursion(dp, arr, target, sum+arr[index], index-1);
        }
        
        int nopick =  recursion(dp, arr, target, sum, index - 1);
        return dp[index][sum] = pick + nopick;
    }
    int perfectSum(vector<int>& arr, int target) {
        
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        return recursion(dp, arr, target, 0, arr.size()-1);
        
    }
};