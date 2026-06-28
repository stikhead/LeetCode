/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        while(!q.empty()){
            auto [parent, child] = q.front();
            q.pop();
            if(parent){

                graph[child->val].push_back(parent->val);
                graph[parent->val].push_back(child->val);
            }
            if(child->left) q.push({child, child->left});
            if(child->right) q.push({child, child->right});


        }

        unordered_map<int, int> vis;
        queue<int> q2;
        q2.push(start);
        vis[start]++;
        int level = -1;
        while(!q2.empty()){
            int size = q2.size();
            level++;
            for(int i=0; i<size; i++){
                int node = q2.front();
                q2.pop();
                for(int j=0; j<graph[node].size(); j++){
                    int child = graph[node][j];
                    if(!vis[child]){
                        q2.push(child);
                        vis[child]++;
                    }
                }
            }
        }
        return level;
    }
};