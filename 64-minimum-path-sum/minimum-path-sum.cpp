class Solution {
public:

    int recursion(vector<vector<int>> &dp, vector<vector<int>>& grid, int m, int n, int r, int c){
        if(r==m-1 && c==n-1) return grid[r][c];
        if(r>=m || c>=n) return 1e9;
        if(dp[r][c]!=-1) return dp[r][c];
        int down = grid[r][c] + recursion(dp, grid, m, n, r+1, c);
        int right = grid[r][c] + recursion(dp, grid, m, n, r, c+1);
        return dp[r][c] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return recursion(dp, grid, grid.size(), grid[0].size(), 0, 0);
    }
};