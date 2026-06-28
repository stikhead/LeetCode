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
    bool dfs(TreeNode* root, TreeNode *& p, TreeNode *& q, TreeNode *& ans){
        if(!root) return false;
        if(!root->left && !root->right) return false;
        if(dfs(root->left, p, q, ans)) return true;
        if(dfs(root->right, p, q, ans)) return true;
        if(root->left==p || root->right==p){
            p = root;
        } 
        if(root->left==q || root->right==q){
            q = root;
        } 
        if(q==p){
            cout<<q->val<<" ";
            ans = q;
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * ans = nullptr;
        dfs(root, p, q, ans);
        return ans;
    }
};