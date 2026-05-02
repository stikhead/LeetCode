class Solution {
public:
    void recursion(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int& target, int& sum, int index) {
        
        if (sum == target) {
            ans.push_back(subset);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            if (sum + nums[i] <= target) {
                sum += nums[i];
                subset.push_back(nums[i]);
                recursion(ans, subset, nums, target, sum, i + 1);
                subset.pop_back();
                sum -= nums[i];
            } 

            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> subset;
        int sum = 0;
        recursion(ans, subset, candidates, target, sum, 0);
        return ans;
    }
};