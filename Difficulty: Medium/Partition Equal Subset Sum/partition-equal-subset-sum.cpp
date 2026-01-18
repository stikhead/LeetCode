class Solution {
  public:
    bool recur(vector<int> &nums, int sum, int n){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(nums[n-1]<=sum){
            return recur(nums, sum - nums[n-1], n - 1) || recur(nums, sum, n-1);
        }
        else {
            return recur(nums, sum, n-1);
        }
    }

    bool equalPartition(vector<int>& arr) {
       int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
        }
        if(sum%2!=0) {
            return false;
        }
        else {
            return recur(arr, sum/2, arr.size());
        }
    }
};