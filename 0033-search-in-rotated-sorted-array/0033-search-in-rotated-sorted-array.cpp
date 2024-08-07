class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while(start <= end){
            int mid = (start + end) /2;
            if(nums[mid] == target) return mid;
            if(nums[start] <= nums[mid]){
                //means left part is sorted
                if(nums[start] <= target and target <= nums[mid]){
                    //means target lies in the left part of the array
                    end = mid -1;
                }else{
                    //means target lies int the right part of the array
                    start = mid +1;
                }
            }else{
                //means right part is sorted
                if(nums[mid+1] <= target and nums[end] >= target){
                    //means target lies in the right part of the array
                    start = mid +1;
                }else{
                    //means target lies int the left part of the array
                    end = mid -1;
                }
            }
        }
        return -1;
    }
};