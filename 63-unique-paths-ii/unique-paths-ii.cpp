class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<vector<int>> &grid, int m, int n, int r, int c){
        if(r>=m || c>=n) return 0;
        if(grid[r][c]==1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==m-1 && c==n-1) return 1;
        int down = recursion(dp, grid, m, n, r+1, c);
        int right = recursion(dp, grid, m, n, r, c+1);
        return dp[r][c]= down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursion(dp, obstacleGrid, m, n, 0, 0);
    }
};