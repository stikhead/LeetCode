/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        vector<int> ans;
        if(!root) return ans;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, x] = q.front();
            q.pop();
           
            mp[x] = node->data;
            
            
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
            
        }
        
        for(auto [key, val] : mp){
            ans.push_back(val);
            
        }
        return ans;
    }
};