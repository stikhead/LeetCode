class Solution {
  public:
  
    int recursion(vector<vector<int>> &dp, vector<int> &val, vector<int> &wt, int index, int remaining_weight){
        if(index==wt.size() || remaining_weight==0){
            return 0; 
        }
        
        if(dp[index][remaining_weight]!=-1) return dp[index][remaining_weight];
        int take = 0;
        if(wt[index]<=remaining_weight){
            take = val[index] + recursion(dp, val, wt, index+1, remaining_weight-wt[index]);
        }
        int skip = recursion(dp, val, wt, index+1, remaining_weight);
        
        return dp[index][remaining_weight] = max(skip, take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int s = W;
        vector<vector<int>> dp(val.size()+1, vector<int>(W+1, -1));
        
        return recursion(dp, val, wt, 0, s);
        
    }
};