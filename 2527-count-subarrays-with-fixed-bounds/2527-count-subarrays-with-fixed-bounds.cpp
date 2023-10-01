class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int min_i = -1;
        int max_j = -1;
        int culind = -1;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < mink or nums[i] > maxk){
                culind = i;
            }
            if(nums[i] == mink){
                  min_i = i;
            }
             if(nums[i] == maxk){
                max_j = i;
            }

            long long smaller = min(min_i,max_j);
            long long temp = smaller - culind;
            ans += (temp <= 0)?0:temp;
            
        }
        return ans;
    }
};