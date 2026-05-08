class Solution {
public:
    int recursion(vector<unordered_map<int, int>> &dp, vector<int> &nums, int target, int index, int sum){
        if(index<0){
            if(sum==target){
                return 1;
            } else {
                return 0;
            }
        }

        if(dp[index].count(sum)) return dp[index][sum];

        int add = recursion(dp, nums, target, index-1, sum+nums[index]);
        int minus = recursion(dp, nums, target, index-1, sum-nums[index]);
        return dp[index][sum] = add + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // int total = 0;
        // for(int i=0;i<nums.size(); i++){
        //     total
        // }
        vector<unordered_map<int, int>> dp(nums.size());
        return recursion(dp, nums, target, nums.size()-1, 0);
    }
};