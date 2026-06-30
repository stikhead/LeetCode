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
    stack<TreeNode*> st;
    void left(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    // vector<int> preorder;
    // void pre(TreeNode* root){
    //     if(root){
    //         pre(root->left);
    //         preorder.push_back(root->val);
    //         pre(root->right);
    //     }
    // }
    // int index;
public:
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    int next() {
        TreeNode * curr = st.top();
        st.pop();

        if(curr->right){
            left(curr->right);
        }
        
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */