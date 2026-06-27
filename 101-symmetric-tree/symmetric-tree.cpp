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
    bool dfs(TreeNode * temp1, TreeNode * temp2){
        if(!temp1 && !temp2){
            return true;
        }

        if((temp1 && !temp2) || (!temp1 && temp2)) return false;
        if(temp1->val!=temp2->val){
            return false;
        }
    	// cout<<temp1->left<<" "<<temp2->left<<", ";
        return dfs(temp1->left, temp2->right) && dfs(temp1->right, temp2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if((root->left && !root->right) || (!root->left && root->right)) return false;
        return dfs(root->left, root->right);
    }
};