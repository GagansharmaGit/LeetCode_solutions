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
    ListNode* removeNodes(ListNode* head) {
        ListNode* tempPtr = head;
        stack<ListNode*> incStack;
        while(tempPtr != NULL){
            while(!incStack.empty() and incStack.top()->val < tempPtr->val){
                cout<<incStack.top()->val<<" ";
                incStack.pop();
            }
            incStack.push(tempPtr);
            tempPtr = tempPtr->next;
        }
        ListNode* temp = NULL;
        while(!incStack.empty()){
            tempPtr = incStack.top();
            incStack.pop();
            tempPtr->next = temp;
            temp = tempPtr;
        }
        return tempPtr;
    }
};