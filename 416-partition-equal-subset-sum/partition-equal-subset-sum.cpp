class Solution {
public:
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
            sum/=2;
            vector<vector<bool>> dp(size+1, vector<bool>(sum+1));
            for(int i=0; i<=sum; i++){
                dp[0][i] = false;
            }
            for(int i=0; i<=size; i++){
                dp[i][0] = true;
            }
            for(int i = 1; i<=size; i++){
                for(int j = 1; j<=sum; j++){
                    if(nums[i-1]<=j){
                        dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                    }
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[size][sum];
        }
    }

    //   memoization
    //     bool dpSol(vector<int> &nums, vector<vector<int>> &dp, int sum, int n){
    //     if(sum==0){
    //         return true;
    //     }
    //     if(n==0){
    //         return false;
    //     }
    //     if(dp[n-1][sum]!=-1){
    //         return dp[n-1][sum];
    //     }
    //     if(nums[n-1]<=sum){
    //         return dp[n-1][sum] = dpSol(nums, dp, sum - nums[n-1], n - 1) || dpSol(nums, dp, sum, n-1);
    //     }
    //     else {
    //         return dp[n-1][sum] = dpSol(nums, dp, sum, n-1);
    //     }
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     int size = nums.size();
    //     for(int i=0; i<nums.size(); i++){
    //         sum+=nums[i];
    //     }
    //     if(sum%2!=0) {
    //         return false;
    //     }
    //     else {
    //         vector<vector<int>> dp(size, vector<int>(sum+1, -1));
    //         return dpSol(nums, dp, sum/2, size);
    //     }
    // }
};

