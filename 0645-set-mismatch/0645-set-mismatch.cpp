class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing = -1;
        int twice = -1;
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0){
                twice = abs(nums[i]);
                 
                
            }else{
                nums[idx] *= -1;
            }
            
        }

        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        return {twice,missing};
    }
};