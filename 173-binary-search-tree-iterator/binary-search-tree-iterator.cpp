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
class BSTIterator {

    vector<int> preorder;
    void pre(TreeNode* root){
        if(root){
            pre(root->left);
            preorder.push_back(root->val);
            pre(root->right);
        }
    }
    int index;
public:
    BSTIterator(TreeNode* root) {
        index  = 0;
        
        
        pre(root);
    }
    
    int next() {
        return preorder[index++];
    }
    
    bool hasNext() {
        
        return index < preorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */