class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int y = target - nums[i];
            if(mp.count(y)){
                return {mp[y], i};
            }
            mp[nums[i]] = i;
        }
        return {};
        
        // int size = nums.size();
        // for(int i=0; i<size-1; i++){
        //     for(int j=i+1; j<size; j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {-1, -1};
    }
    
};