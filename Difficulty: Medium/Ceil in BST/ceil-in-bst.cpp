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
    
    int findCeil(Node* root, int x) {
        // code here
        int m = INT_MAX;
        bool isCeil = false;
        Node * temp = root;
        while(temp){
            if(temp->data==x) {
                return temp->data;
            } 
            else if (temp->data > x){
                m = min(m, temp->data);
                isCeil = true;
                temp=temp->left;
            } else {
                if(!temp->right);
                temp=temp->right;
            }
        }
        return isCeil ? m : -1;
    }
};
