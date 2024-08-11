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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         int carry=0;
         ListNode*temp=new ListNode(0);
         ListNode*a=temp;

        while(l1||l2){
         int sum=carry;
         if(l1!=0){
             sum=sum+l1->val;
             l1=l1->next;
         }
         if(l2!=0){
             sum=sum+l2->val;
             l2=l2->next;
         }
          if(sum>9){
              carry=1;
              sum=sum%10;
          }else{
              carry=0;
          }
          
          a->next=new ListNode(sum);
          a=a->next;
          }
           if(carry!=0){
              a->next=new ListNode(carry);
          }
           return temp->next;
    }
};