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
    int recur(TreeNode * root, int& pathsum){
        if(!root){
            return 0;
        }

        int left = recur(root->left, pathsum);
        // if(left<0) return 0;
        int right = recur(root->right, pathsum);
        // if(right<0) return 0;
        int isRootBig = left+right+root->val;
        if(left<0 && right< 0){
            isRootBig = root->val;
        } else if(right<0){
            isRootBig = left+root->val;
        } else if(left<0){
              isRootBig = right+root->val;
        }
        pathsum = max(pathsum, isRootBig); 
        return left+right>0 ? root->val + max(left, right) : isRootBig;

    }
    int maxPathSum(TreeNode* root) {
        int pathsum = INT_MIN;
        recur(root, pathsum);
        return pathsum;
    }
};