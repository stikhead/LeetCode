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

    int recur(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = recur(root->left);
        if(left == -1) return -1;
        int right = recur(root->right);
        if(right == -1 ) return -1;
        if(abs(left-right) > 1) return -1;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
    //    if(!root) return true;
    //    int left = recur(root->left);
    //    int right = recur(root->right);

    //    if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
    //         return true;
    //     }
        
    //     return false;
        return recur(root)==-1 ? false : true;
    }
};