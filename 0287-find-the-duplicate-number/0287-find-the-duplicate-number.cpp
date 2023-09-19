class Solution {
public:
    int findDuplicate(vector<int>& nu) {
        int slow=nu[0];
        int fast=nu[0];
        do{
            slow=nu[slow];
            fast=nu[nu[fast]];
        }while(slow!=fast);
        fast=nu[0];
        while(slow!=fast){
            slow=nu[slow];
            fast=nu[fast];
        }
        return slow;
    }
};