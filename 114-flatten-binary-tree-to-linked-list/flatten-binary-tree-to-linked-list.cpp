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
    void preorder(TreeNode* root, TreeNode*& ll){
        if(root){
            TreeNode * tempLeft = root->left;
            TreeNode * tempRight = root->right;
            
            ll->right = root;
            ll->left = nullptr;
            ll = root;
            preorder(tempLeft, ll);
            preorder(tempRight, ll);
            
           
        }
    }
    void flatten(TreeNode* root) {
        TreeNode dummy(0);
        TreeNode * linkedlist = &dummy;
        preorder(root, linkedlist);
        
        root = dummy.right;
        
    }
};