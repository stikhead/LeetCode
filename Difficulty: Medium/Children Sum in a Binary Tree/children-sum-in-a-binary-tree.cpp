/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    
    bool isSumProperty(Node *root) {
        if(!root) {
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        
        if(root && !root->left && root->right){
            if(root->right->data != root->data) return false;
        }
        if(root && root->left && !root->right){
            if(root->left->data != root->data) return false;
        }
        if(root->left && root->right){
            if(root->left->data+root->right->data!=root->data) return false;
        }
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};