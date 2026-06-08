class Solution {
public:
    int findMax(unordered_map<char, int>& items) {
        auto it = items.begin();
        int max_key = it->second;

        for (const auto& pair : items) {
            if (pair.second > max_key) {
                max_key = pair.second;
            }
        }
        // cout<<max_key<<" ";
        return max_key;
    }
    bool dfs(vector<vector<int>>& list, string& colors, vector<int>& vis,
             vector<vector<int>>& dp, int& mx, int node) {
        vis[node] = 1;
        int col = colors[node] - 'a';
        dp[node][col] = 1;
        for (int i = 0; i < list[node].size(); i++) {
            int child = list[node][i];
            if (vis[child] == 0) {
                if (dfs(list, colors, vis, dp, mx, child)) {
                    return true;
                }
            } else if (vis[child] == 1) {
                return true;
            }
            for (int c = 0; c < 26; c++) {
                int added_value = (c == col) ? 1 : 0;
                dp[node][c] = max(dp[node][c], dp[child][c] + added_value);
            }
        }
        // cout<<mx<<" ";
        for (int c = 0; c < 26; c++) {
            mx = max(mx, dp[node][c]);
        }
        vis[node] = 2;
        return false;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> list(colors.size());
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            list[a].push_back(b);
        }

        int mx = 0;
        vector<int> vis(colors.size(), 0);
        vector<vector<int>> dp(colors.size(), vector<int>(26, 0));
        unordered_map<char, int> mp;
        for (int i = 0; i < colors.size(); i++) {
            if (vis[i] == 0) {
                if (dfs(list, colors, vis, dp, mx, i))
                    return -1;
            }
        }
        return mx;
    }
};