class Solution {
public:
    void recursion(vector<vector<int>> &ans, vector<int> &subset, vector<int> &nums, int index){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }

        
        subset.push_back(nums[index]);
        recursion(ans, subset, nums, index + 1);
        subset.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++; 
        }
        recursion(ans, subset, nums, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        recursion(ans, subset , nums, 0);
        return ans;
    }
};