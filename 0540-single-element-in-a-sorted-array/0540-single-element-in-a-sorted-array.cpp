class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[size-1] != nums[size-2]) return nums[size-1];

        int start = 0;
        int end = size -1;
        while(start <= end){
            int mid = (start + end) /2;
            if(nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]) return nums[mid];

            if((mid %2 == 0) and (nums[mid] == nums[mid+1]) or (mid %2 != 0) and (nums[mid] == nums[mid -1])){
                start = mid +1;
            }else{
                end = mid -1;
            }
        }
        return -1;
    }
};