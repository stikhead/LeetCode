/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        if(slow && slow->next){
            ListNode* temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }
        return dummy.next;
        // int size = 0;
        // if(!head){
        //     return head;
        // }
        // if(!head->next && n==1){
        //     return nullptr;
        // }
        // ListNode * temp = head;
        // while(temp){
        //     temp=temp->next;
        //     size++;
        // }
        // if(size-n==0){
        //     return head->next;
        // }
        // temp = head;
        // for(int i=0; i<size-n-1; i++){
        //     temp = temp->next;
        // }
        // if(temp && temp->next){
        //     ListNode * storeDeletedNode = temp->next;
        //     temp->next = temp->next->next;
        //     delete storeDeletedNode;
        // }
        // return head;
    }
};