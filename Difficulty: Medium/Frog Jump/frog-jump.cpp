class Solution {
  public:

    int recursion(vector<int> &dp, vector<int>& height, int n, int index){
    if(index==n-1){
        return 0;
    }
    
    if(dp[index]!=-1) return dp[index];
    int onestep =INT_MAX;
    if(index+1<n){
    onestep = abs(height[index] - height[index+1]) + recursion(dp, height, n, index+1);
    
    }
    int twostep =INT_MAX;
    if(index+2<n){
        twostep = abs(height[index] - height[index+2]) + recursion(dp, height, n, index+2);
            }
     dp[index] = min(onestep, twostep);
     return dp[index];
} 
int minCost(vector<int>& height) {
    int cost = 0;
    int n = height.size();
    vector<int> dp(n+1,-1);
 
    return recursion(dp, height, n, 0);
    // code here
    
}
};