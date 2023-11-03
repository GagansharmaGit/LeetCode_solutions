class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxi = INT_MIN;
        sort(begin(nums),end(nums));

        for(int i=2;i<nums.size();i++){
            if(nums[i-2] + nums[i-1] > nums[i]){
                maxi = max(maxi,nums[i]+nums[i-1]+nums[i-2]);
            }
        }

        if(maxi == INT_MIN) return 0;
        return maxi;
    }
};