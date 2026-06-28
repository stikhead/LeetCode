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
   
    int countNodes(TreeNode* root) {
        // if(!root) return 0;
        // if(!root->left && !root->right) return 1;
        // int left = countNodes(root->left);
        // int right = countNodes(root->right);
        // return left+right+1;
        if(!root) return 0;
        int left = 1;
        TreeNode *l = root->left;
        while(l){
            l=l->left;
            left++;
        }
        int right = 1;
        TreeNode * r = root->right;
        while(r){
            r=r->right;
            right++;
        }

        if(left==right) return (1<<left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};