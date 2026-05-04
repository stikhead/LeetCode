// class Solution {
// public:
//     int recursion(vector<int> &dp, vector<int> &nums, int n, int index, int end){
//         if(index> end){
//             return 0;
//         }
//         if(dp[index]!=-1) return dp[index];

//         int rob = nums[index] + recursion(dp, nums, n, index+2, end);
     
//         int dontrob = recursion(dp, nums, n, index+1, end);

//         return dp[index] = max(rob, dontrob);
//     }
//     int rob(vector<int>& nums) {
//         if(nums.size()==1){
//             return nums[0];
//         }
//         vector<int> dpA(nums.size(), -1);
//         vector<int> dpB(nums.size(), -1);
//         int a =  recursion(dpA, nums, nums.size(), 0, nums.size()-2);
         
//         int b =  recursion(dpB, nums, nums.size(), 1, nums.size()-1);
//         return max(a, b);
//     }
// };

class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<int> &nums, int n, int index, bool flag){
        if(index>=n){
            return 0;
        }
        if(dp[index][flag]!=-1) return dp[index][flag];
        if((index+1)%n==0 && flag){
            return 0;
        }
        bool didrob = index==0 ? true  : flag;
        int rob = nums[index] + recursion(dp, nums, n, index+2, didrob);
        int dontrob = recursion(dp, nums, n, index+1, flag);

        return dp[index][flag] = max(rob, dontrob);
    }
    int rob(vector<int>& nums) {
        bool first = false;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return recursion(dp, nums, nums.size(), 0, false);
    }
};