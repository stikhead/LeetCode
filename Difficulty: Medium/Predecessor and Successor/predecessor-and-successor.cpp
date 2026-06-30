/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> pred = {nullptr, nullptr};
        Node * temp = root;
        while(temp){
            if(temp->data==key){
                if(temp->left){
                    Node* prev=temp->left;
                    while(prev->right){
                        prev=prev->right;
                    }
                    pred[0] = prev;
                }
                if(temp->right){
                    Node* succ=temp->right;
                    while(succ->left){
                        succ=succ->left;
                    }
                    pred[1] = succ;
                }
                return pred;
            }
            if(temp->data > key){
                pred[1] = temp;
                temp = temp->left;
            } else if(temp->data < key){
                pred[0] = temp;
                temp = temp->right;
            }
            
        }
        return pred;
    }
};