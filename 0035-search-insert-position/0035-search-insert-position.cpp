class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int ansInd = nums.size();
        while(start <= end){
            int mid = (start + end) / 2;
            
            if(nums[mid] >= target){
                ansInd = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ansInd;
    }
};