class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<pair<int, int>> dir = {
            {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
        };
        
        queue<pair<int, int>> q;
        q.push({knightPos[0], knightPos[1]});
        int minStep = 0;
        vector<vector<int>> visited(n+1, vector<int>(n+1, 0));
        visited[knightPos[0]][knightPos[1]] = 1;
        while(!q.empty()){
            int size = q.size();
            minStep++;
            for(int i=0; i<size; i++){
                auto [row, col] = q.front();
                
                q.pop();
                for(int j=0; j<8; j++){
                    int nrow = row + dir[j].first;
                    int ncol = col + dir[j].second;
                    
                    if(nrow>0 && nrow<=n && ncol >0 && ncol <=n){
                        if(targetPos[0]==nrow && targetPos[1]==ncol){
                           return minStep;
                        }
                        if(!visited[nrow][ncol]){
                            q.push({nrow, ncol});
                            visited[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};