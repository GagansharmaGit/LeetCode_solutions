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
    ListNode* removeElements(ListNode* head, int val) {
        int value=val;
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;

        ListNode* temp=dummy;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==value){
                ListNode* temp1=temp->next;
                temp->next=temp1->next;
                delete temp1;
            }
            else{
                temp=temp->next;
            }
        }
    return dummy->next;    
    }
};