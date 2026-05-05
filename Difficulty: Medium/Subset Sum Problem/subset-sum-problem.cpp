class Solution {
  public:
  
    bool recursion(vector<vector<int>>&dp, vector<int> &arr, int sum, int index, int acc){
        if(acc==sum){
            return true;
        }
        if(index>=arr.size() || acc>sum){
            return false;
        }
        
        
        if(dp[index][acc]!=-1) return dp[index][acc];
        
        bool pick = recursion(dp, arr, sum, index+1, acc+arr[index]);
        bool nopick = recursion(dp, arr, sum, index+1, acc);
        return dp[index][acc] = (pick || nopick);
        
        
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size(), vector<int>(sum, -1));
        return recursion(dp, arr, sum, 0, 0);
        
    }
};