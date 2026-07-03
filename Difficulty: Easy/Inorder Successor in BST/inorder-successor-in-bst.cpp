/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        if(!root){
            return -1;
        }
        
        Node * temp = root;
        Node * succ = nullptr;
        while(temp){
            // cout<<temp->data<<" ";
            // if(temp==k){
            //     if(temp->right){
            //         temp = temp->right;
            //         while(temp->left){
            //             temp = temp->left;
            //         }
            //         return temp->data;
            //     } else {
            //         return -1;
            //     }
            // }
            if(temp->data <= k->data){
                temp = temp->right;
            } else {
                succ = temp;
                temp = temp->left;
            }
        }
       
        return succ ? succ->data : -1;
    }
};