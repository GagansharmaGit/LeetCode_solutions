class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k;
        int ans = nums[k];
        int mini = nums[k];
        while(i > 0 or j<nums.size()-1){

            int left_side = (i>0)?nums[i-1]:0;
            int right_side = (j<nums.size()-1)?nums[j+1]:0;

            if(right_side > left_side){
                mini = min(mini,nums[j+1]);
                j++;
            }else{
                mini = min(mini,nums[i-1]);
                i--;
            }

            
            ans = max(ans,mini*(j-i+1));
        }

        return ans;
    }
};