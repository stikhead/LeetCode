class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dir = {{0,1}, {-1, 0}, {1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        int freshOrange = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } 
                if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
        if(freshOrange==0) return 0;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0; i<size; i++){
                auto [row, col] = q.front();
                q.pop();
                for(int j=0; j<4; j++){
                    int nrow = row + dir[j].first;
                    int ncol = col + dir[j].second;

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                        if(grid[nrow][ncol]==1){
                            grid[nrow][ncol]=2;
                            freshOrange--;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
        }

        

        return freshOrange > 0 ? -1: level-1;
    }
};