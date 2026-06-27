/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
    
  public:
 
    vector<int> topView(Node *root) {
        map<int, int> mp;
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, x] = q.front();
            q.pop();
            if(mp[x]==0) mp[x]=node->data;
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
            
        }
        for(auto [key, val]: mp){
            ans.push_back(val);
        }
        return ans;
    }
};