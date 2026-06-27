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
    void addLeft(Node * root, vector<int> &ans){
        while(root){
            if(root->left || root->right){
                ans.push_back(root->data);
            }
            if(root->left) root = root->left;
            else root=root->right;
        }
    }
    
    void addRight(Node * root, vector<int> &ans){
        vector<int> temp;
        while(root){
            if(root->left || root->right){
                temp.push_back(root->data);
            }
            if(root->right) root = root->right;
            else root=root->left;
        }
        
        for(int i=temp.size()-1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
    
    void dfs(Node *root, vector<int> &ans){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        if(root->left) dfs(root->left, ans);
        if(root->right) dfs(root->right, ans);
        return;
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        if(root->left || root->right) ans.push_back(root->data);
        addLeft(root->left, ans);
        dfs(root, ans);
        addRight(root->right, ans);
        return ans;
    }
};