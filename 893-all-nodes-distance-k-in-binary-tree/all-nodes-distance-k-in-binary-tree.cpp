/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({nullptr, root});
        while(!q.empty()){
            auto [parent, child] = q.front();
            q.pop();
            if(parent){
                graph[child].push_back(parent);
                graph[parent].push_back(child);
            }
            if(child->left) q.push({child, child->left});
            if(child->right) q.push({child, child->right});
        }
        // for(auto [parent, vec] : graph){
        //     cout<<parent->val<<": ";
        //     for(auto i : vec){
        //         cout<<i->val<<" ";
        //     }
        //     cout<<endl;
        // }
    
        vector<int> ans;
        queue<TreeNode*> q2;
        unordered_map<TreeNode*, int> vis;
        int level = 0;
        q2.push(target);
        vis[target]++;
        while(!q2.empty()){
            int size = q2.size();
            for(int i=0; i<size; i++){
                auto node = q2.front();
                q2.pop();
                if(level==k){
                    ans.push_back(node->val);
                }

                for(int i=0; i<graph[node].size(); i++){
                    if(!vis[graph[node][i]]){
                        vis[graph[node][i]]++;
                        q2.push(graph[node][i]);
                    }
                }
                
            }
            if(level==k) return ans;
            level++;
        }
      
 
        return ans;
    }
};