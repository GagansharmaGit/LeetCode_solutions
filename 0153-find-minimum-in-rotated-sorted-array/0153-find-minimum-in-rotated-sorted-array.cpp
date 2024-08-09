class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int start = 0;
        int end = nums.size() -1;

        while(start <= end){
            int mid = (start + end) /2;
            if(nums[start] <= nums[mid]){
                //Means left part is sorted
                ans = min(nums[start] , ans);
                start = mid +1;
            }else{
                //Means right part is sorted
                ans = min(nums[mid] , ans);
                end = mid -1;
            }
        }
        return ans;
    }
};