class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = false;
        bool decreasing = false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                increasing = true; 
            }
            if(nums[i] > nums[i+1]){
                decreasing = true;
            }
        }
        if(increasing == true and decreasing == true){
            return false;
        }
        return true;
    }
};