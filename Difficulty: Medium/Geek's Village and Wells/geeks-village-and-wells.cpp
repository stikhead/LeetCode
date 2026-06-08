// User function Template for C++

class Solution {
	public:
	vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c) {
		// Code here
		vector<vector<int>> ans(n, vector<int>(m, 0));
		vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
		queue<pair<int, int>> q;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (c[i][j] == 'W') {
					q.push({i, j});
				}
				if (c[i][j] == 'H' || c[i][j]=='.') {
					ans[i][j] = -1;
				}
				
			}
		}
		
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			for (int k = 0; k<4; k++) {
				int nx = x + dir[k].first;
				int ny = y + dir[k].second;
				if (nx >= 0 && nx < n && ny >= 0 && ny<m) {
					if (ans[nx][ny] == -1 ) {
						ans[nx][ny] = 2 + ans[x][y];
						q.push({nx, ny});
						
					}
				}
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (c[i][j]=='.') {
					ans[i][j] = 0;
				}
				
			}
		}
		return ans;
	}
};
