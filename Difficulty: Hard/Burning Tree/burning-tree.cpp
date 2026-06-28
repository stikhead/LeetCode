/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<int, vector<int>> adj;
        queue<pair<Node*, Node*>> q;
        q.push({nullptr, root});
        while(!q.empty()){
            auto [parent, node] = q.front();
            q.pop();
            
            if(parent){
                adj[node->data].push_back(parent->data);
                
                adj[parent->data].push_back(node->data);
            }
            if(node->left) q.push({node, node->left});
            if(node->right) q.push({node, node->right});
            
            
        }
        
      
        
        unordered_map<int, int> vis;
        queue<int> q2;
        
        q2.push(target);
        vis[target]++;
        int level = -1;
        while(!q2.empty()){
            int size = q2.size();
            for(int i=0; i<size; i++){
                int node = q2.front();
                q2.pop();
                for(int j = 0; j<adj[node].size(); j++){
                    int child = adj[node][j]; 
                    if(!vis[child]){
                        vis[child]++;
                        q2.push(child);
                        
                    }
                }
            }
            level++;
        }
       
        return level;
    }
};