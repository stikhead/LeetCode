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
    unordered_map<int, int> mp;
    TreeNode * recursion(vector<int>& preorder, vector<int>& inorder, int PreorderStartIndex, int PreorderEndIndex, int inorderStartIndex, int inorderEndIndex){
        if(PreorderStartIndex > PreorderEndIndex || inorderStartIndex > inorderEndIndex) return nullptr;
        TreeNode * node = new TreeNode(preorder[PreorderStartIndex]);
        int root = mp[node->val];
        int leftsubtree = root - inorderStartIndex;
        node->left = recursion(preorder, inorder, PreorderStartIndex+1, PreorderEndIndex+leftsubtree, inorderStartIndex, root-1);
        node->right = recursion(preorder, inorder, PreorderStartIndex+1+leftsubtree, PreorderEndIndex, root+1, inorderEndIndex);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return recursion(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};