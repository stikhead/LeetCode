/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int m = -1;
        Node * temp = root;
        while(temp){
            if(temp->data==k) return k;
            else if(temp->data > k){
                temp = temp->left;
            } else {
                m = temp->data;
                temp = temp->right;
            }
        }
        return m;
    }
};