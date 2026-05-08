class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &arr, int index, int sum, int total, int diff) {
        
        if(index<0){
            if((total-sum-sum)==diff){
                return 1;
            } else {
                return 0;
            }
            
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        
        int left = recursion(dp, arr, index-1, sum+arr[index], total, diff);
        int right = recursion(dp, arr, index-1, sum, total, diff);
        return dp[index][sum]=left+right;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int total = 0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        
        vector<vector<int>> dp(arr.size()+1, vector<int>(total+1, - 1));
        return recursion(dp,arr, arr.size() - 1, 0, total, diff);
        
    }
};