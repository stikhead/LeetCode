class Solution {
  public:
    int recursion(vector<vector<int>> &dp, vector<int> &val, vector<int> &wt, int capacity, int index){
      if(capacity==0){
                return 0;
            }
        
        if(index<0){
            
            return 0;
        }
        
        if(dp[index][capacity]!=-1) return dp[index][capacity];
        
        for(int i=index; i>=0; i--){
            int pick = 0;
            if(capacity-wt[index]>=0){
                pick = val[index] + recursion(dp, val, wt, capacity-wt[index], index);
            } 
            
            int noPick = recursion(dp, val, wt, capacity, index-1);
        
            return dp[index][capacity] = max(pick, noPick);
        }
        
        return 0;
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<vector<int>> dp(wt.size()+1, vector<int>(capacity+1, -1));
        return recursion(dp, val, wt, capacity, wt.size()-1);
        
    }
};