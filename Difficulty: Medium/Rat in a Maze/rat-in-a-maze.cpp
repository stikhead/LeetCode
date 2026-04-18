class Solution {
  public:
  
    void backtrack(vector<string> &output, vector<vector<int>>& maze, string &op, int r, int c){
        if(r==maze.size()-1 && c == maze[0].size() - 1){
            output.push_back(op);
            return;
        }
        
        if(r>=0 && r<maze.size() && c >=0 && c < maze[0].size()){
            if(maze[r][c]==1){
                maze[r][c] = 0;
                op.push_back('D');
                backtrack(output, maze, op, r+1, c);
                op.pop_back();
                op.push_back('U');
                backtrack(output, maze, op, r-1, c);
                op.pop_back();
                op.push_back('R');
                backtrack(output, maze, op, r, c+1);
                op.pop_back();
                op.push_back('L');
                backtrack(output, maze, op, r, c-1);
                op.pop_back();
                maze[r][c] = 1;
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> output = {};
        string op = "";
        backtrack(output, maze, op, 0, 0);
        sort(output.begin(), output.end());
        return output;
        
    }
};