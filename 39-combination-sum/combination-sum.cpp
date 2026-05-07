class Solution {
public:
    void recursion(vector<vector<int>> &ans, vector<int> & nums, vector<int> &subset, int index, int & sum, int &target){
        if(sum==target){
            ans.push_back(subset);
            return;
        }


        for(int i=index; i<nums.size(); i++){
            if (sum + nums[i] > target) {
                break; 
            }
           if(sum+nums[i]<=target){
                sum+=nums[i];
                subset.push_back(nums[i]);
                recursion(ans, nums, subset, i, sum, target);
                subset.pop_back();
                sum-=nums[i];
           }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans = {};
        vector<int> subset;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        recursion(ans, candidates, subset, 0, sum, target);
        return ans;
    }
};