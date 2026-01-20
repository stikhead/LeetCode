class Solution {
public:
        // subset1 - subset2 = diff --- i
        // sum[subset1 + subset2] = sumofarrayelements ---- ii
        // adding both equations
        // 2*subset1 = diff + sumofarrayelements
    int recur(vector<int>& nums, vector<vector<int>> &dp, int target, int n){
        if(target==0 && n==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n-1][target]!=-1){
            return dp[n-1][target];
        }
        if(nums[n-1]<=target){
            return dp[n-1][target] = recur(nums, dp, target - nums[n-1], n-1) + recur(nums, dp, target, n-1);
        }
        else {
            return dp[n-1][target] = recur(nums, dp, target, n-1);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumofarray = 0;
        for(int i=0; i<nums.size(); i++){
            sumofarray+=nums[i];
        }
        if(sumofarray < target) return 0;
        if((sumofarray+target)<0 || ((sumofarray+target) % 2) != 0) return 0;
        int subset1 = (target + sumofarray)/2;
        vector<vector<int>> dp(nums.size(), vector<int>(subset1+1, -1));
        return recur(nums, dp, subset1, nums.size());
     
    }
};