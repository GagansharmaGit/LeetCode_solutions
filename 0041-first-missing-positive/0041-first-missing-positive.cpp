class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] <= 0 or nums[i] > n){
                nums[i] = n+1;
            }
        }
        for(int i=0;i<n;i++){
            int ind = abs(nums[i]) - 1;
            if(ind < n){
                nums[ind] = -1 * abs(nums[ind]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};