class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> list(n+1);
        for(int i=0; i<times.size(); i++){
            int source = times[i][0];
            int destination = times[i][1];
            int time = times[i][2];
            list[source].push_back({destination, time});
        }

        vector<int> vis(n+1, INT_MAX);
        priority_queue<pair<int, int>> q;
        q.push({k, 0});
        vis[k] = 0;
        int total_time = 0;
        while(!q.empty()){
            int max_time_level = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [node, time] = q.top();
                q.pop();
                if(vis[node] < time) continue;
                for(int j=0; j<list[node].size(); j++){
                    int child = list[node][j].first;
                    int childTime = list[node][j].second;
                    if(vis[child] > childTime + time){
                        vis[child] = childTime + time;
                        q.push({child, vis[child]});
                    }
                }

            }

        }
        for(int i=1; i<=n; i++){
            if(vis[i]==INT_MAX){
                return -1;
            }
            total_time = max(total_time, vis[i]);
        }
        return total_time;
    }
};