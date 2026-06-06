class Solution {
	public:
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		vector<pair<int, int>> dir = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
		{-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
		queue<pair<int, int>> q;
		vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
		q.push({knightPos[0], knightPos[1]});
		int steps = 0;
		vis[knightPos[0]][knightPos[1]] = true;
		while (!q.empty()) {
			int size = q.size();
			steps++;
			for (int i = 0; i<size; i++) {
				auto [row, col] = q.front();
				q.pop();
				for (int j = 0; j<8; j++) {
					int nrow = row + dir[j].first;
					int ncol = col + dir[j].second;
					
					if (nrow > 0 && nrow <= n && ncol <= n && ncol > 0) {
						if (nrow == targetPos[0] && ncol == targetPos[1]) {
							return steps;
						}
						if (vis[nrow][ncol] == false) {
							q.push({nrow, ncol});
				            vis[nrow][ncol] = true;
							
						}
						
					}
				}
			}
		}
		
		return 0;
		
	}
};
