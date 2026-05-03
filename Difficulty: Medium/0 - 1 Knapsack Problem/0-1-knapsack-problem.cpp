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
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        
        // return recursion(dp, val, wt, 0, s);
        for(int i=0; i<=W; i++){
            dp[0][i] = 0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(wt[i-1]<=j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
        
    }
};