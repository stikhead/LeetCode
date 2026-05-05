class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<vector<int>> &triangle, int r, int c, int m){
        if(r>=m || c>=triangle[r].size()) return 0;
        if(r==m-1 && c<triangle[r].size()){
            return triangle[r][c];
        }

        if(dp[r][c]!=1e9) return dp[r][c];

        int down = triangle[r][c] + recursion(dp, triangle, r+1, c, m);
        int adj = triangle[r][c] + recursion(dp, triangle, r+1, c+1, m);
        return dp[r][c] = min(down, adj);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);
        for(int i=0; i<m; i++){
            dp[i] =  vector<int>(triangle[i].size(), 1e9);
            
        }
        return recursion(dp, triangle, 0, 0, triangle.size());
    }
};