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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(nums.size() == 0) return head;

        unordered_set<int> toremove(nums.begin(), nums.end());

        while(head){
            if(toremove.count(head->val)){
                head = head->next;
            }else{
                break;
            }
        }

        ListNode* newHead = head;

        while(head and head->next){
            if(toremove.count(head->next->val)){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return newHead;
    }
};