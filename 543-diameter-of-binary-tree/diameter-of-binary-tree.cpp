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
    int recur(TreeNode *root, int& maximum){
        if(!root){
            return 0;
        }

        int left = recur(root->left, maximum);
        int right = recur(root->right,  maximum);
        maximum = max(maximum, left+right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maximum = 0;
        recur(root, maximum);
        return maximum;
        // if(!root) return 0;
        // int left = recur(root->left);
        // int right = recur(root->right);
        // int temp = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        // int ans = max(left+right, temp);
        // return ans;
    }
};