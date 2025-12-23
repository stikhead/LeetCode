class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // vector<int> ans;
        // for(int i=0; i<nums.size(); i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]]>1){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;
        // sort(nums.begin(), nums.end());
        // vector<int> ans;
        // for(int i=0; i<nums.size()-1; i++){
        //     if(nums[i]==nums[i+1]){
        //         if(ans.empty()){
        //             ans.push_back(nums[i]);
        //         }
        //         else if(ans.back()!=nums[i]){
        //             ans.push_back(nums[i]);
        //         }
                
        //     }
        // }
        // return ans;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                ans.push_back(index + 1);
            }
            else {
                nums[index] = -nums[index];
            }
        }
    return ans;
    }
};