/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> order;
        Node* current = root;
        while(current){
            if(current->left==nullptr){
                order.push_back(current->data);
                current=current->right;
            } else {
                Node * prev = current->left;
                while(prev->right && prev->right!=current){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right = current;
                    order.push_back(current->data);
                    current = current->left;
                }
                
                if(prev->right==current){
                    prev=nullptr;
                    current=current->right;
                }
            }
        }
        return order;
    }
};