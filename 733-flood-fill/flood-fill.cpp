class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        int orignalColor = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();
            for(int j = 0; j<4; j++){
                int nrow = row + dir[j].first;
                int ncol = col + dir[j].second;

                if(nrow >=0 && nrow<m && ncol >= 0 && ncol < n){
                    if(image[nrow][ncol] == orignalColor){
                        image[nrow][ncol] = color;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return image;
    }


};