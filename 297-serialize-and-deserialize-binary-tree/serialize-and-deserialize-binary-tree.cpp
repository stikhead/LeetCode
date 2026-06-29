/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int preorderindex = 0;
    void preorder(TreeNode* node, string& s) {
        if (node) {
            s += to_string(node->val) + ",";
        } else {
            s += "N,";
            return;
        }
        preorder(node->left, s);
        preorder(node->right, s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s2 = "";
        preorder(root, s2);
        return s2;
    }

    TreeNode* recursion(queue<string>& q) {
        string s = q.front();
        q.pop();
        // cout<<s<<" ";
        if (s == "N"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(s));

        node->left = recursion(q);
        node->right = recursion(q);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";
        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                q.push(temp);
                temp = "";
                continue;
            }
            temp += data[i];
        }

        return recursion(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));