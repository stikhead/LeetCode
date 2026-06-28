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
    void dfs(Node * root, vector<vector<int>> &ans, vector<int> &temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            temp.pop_back();
        }
        temp.push_back(root->data);
        dfs(root->left, ans, temp);
        dfs(root->right, ans, temp);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, ans, temp);
        return ans;
    }
};