class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &arr, int index, int total, int sum){
       // cout<<total<<" "<<sum<<", ";
        if(index<1){
           // cout<<abs(total-sum-sum)<<"* ";
            return abs(total-sum-sum);
        }
        if(dp[index][sum]!=-1){
          //  cout<<dp[index][sum]<<"dp ";
            return dp[index][sum];
        }
        int left = recursion(dp, arr, index-1, total, sum+arr[index]);
        int right = recursion(dp, arr, index-1, total, sum);
        return dp[index][sum] = min(left, right);
    }
    int minDifference(vector<int>& arr) {
        int total = 0;
        for(int i=0; i<arr.size();i++){
            total+=arr[i];
        }
       // cout<<total<<", ";
        vector<vector<int>> dp(arr.size()+1,vector<int>(total+1,-1));

        return recursion(dp, arr, arr.size()-1,total, 0);
        
    }
};
