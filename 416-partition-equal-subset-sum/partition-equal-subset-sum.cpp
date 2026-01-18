class Solution {
public:
    bool dpSol(vector<int> &nums, vector<vector<int>> &dp, int sum, int n){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n-1][sum]!=-1){
            return dp[n-1][sum];
        }
        if(nums[n-1]<=sum){
            return dp[n-1][sum] = dpSol(nums, dp, sum - nums[n-1], n - 1) || dpSol(nums, dp, sum, n-1);
        }
        else {
            return dp[n-1][sum] = dpSol(nums, dp, sum, n-1);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2!=0) {
            return false;
        }
        else {
            vector<vector<int>> dp(size, vector<int>(sum+1, -1));
            return dpSol(nums, dp, sum/2, size);
        }
    }
};