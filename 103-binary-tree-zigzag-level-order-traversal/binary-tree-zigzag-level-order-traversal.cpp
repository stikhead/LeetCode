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
   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        if(!root) return ans;
        q.push_back(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node;
                if(level%2==0){
                    node = q.front();
                    q.pop_front();
                    if(node->right) q.push_back(node->right);
                    if(node->left) q.push_back(node->left);
                } else {
                    node = q.back();
                    q.pop_back();
                        if(node->left) q.push_front(node->left);
                        if(node->right) q.push_front(node->right);
                }
                // cout<<level<<" ";
                // cout<<node->val<<" ";
                temp.push_back(node->val);
            }
           
            ans.push_back(temp);
        }
        return ans;
    }
};