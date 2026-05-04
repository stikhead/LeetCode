class Solution {
public:
    int recursion(vector<int>&dp, vector<int> &nums, int index, int n){
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1) return dp[index];

        int rob = nums[index] + recursion(dp, nums, index+2, n);
        int dontrob = recursion(dp, nums, index+1, n);
        dp[index] = max(rob, dontrob);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return recursion(dp, nums, 0, nums.size());
    }
};