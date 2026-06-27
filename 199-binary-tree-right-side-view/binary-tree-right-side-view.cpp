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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> mp(100);
        if(!root) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i=0; i<size; i++){
            auto [node, x] = q.front();
            q.pop();
            mp[x] = node->val;
            if(node->left) q.push({node->left, x+1});
            if(node->right) q.push({node->right, x+1});
            }
        }
        mp.resize(level);
        return mp;
    }
};