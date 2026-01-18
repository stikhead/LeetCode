class Solution {
  public:
    bool recur(vector<int>& arr, int sum, int n){
        if(sum == 0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(arr[n-1]<=sum){
            return recur(arr, sum - arr[n-1], n-1) || recur(arr, sum, n-1);
        }
        else {
            return recur(arr, sum, n-1);
        }
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // vector<vector<int>> dp(arr.size(), vector<int>(sum+1)) 
        int size = arr.size();
        return recur(arr, sum, size);
    }
};