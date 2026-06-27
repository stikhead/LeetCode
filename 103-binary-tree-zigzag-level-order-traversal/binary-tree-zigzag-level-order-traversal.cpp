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
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // cout<<level<<" ";
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                cout<<node->val<<" ";
                temp.push_back(node->val);
            }
            if(level%2==0){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};