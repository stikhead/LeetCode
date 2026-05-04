class Solution {
public:
    int recursion(vector<vector<int>> &dp, int m, int n, int r, int c){
        if(r>=m || c>=n){
            return 0;
        }
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        
        int down = recursion(dp, m, n, r+1, c);
        int right = recursion(dp, m, n, r, c+1);
        
        return dp[r][c] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursion(dp, m, n, 0, 0);
    }
};