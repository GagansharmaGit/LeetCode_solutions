class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moore voting algorithm
        int element=0;
        int count=0;
        for(auto x:nums){
            if(count==0){
                element=x;
            }
            if(x==element){
                count +=1;
            }else{
                count -= 1;
            }
        }
        return element;
    }
};