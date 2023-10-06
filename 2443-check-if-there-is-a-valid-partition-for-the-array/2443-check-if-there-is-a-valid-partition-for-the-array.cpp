class Solution {
public:
    bool solve(int i,vector<int>&nums,vector<int>&dp){
        if(i >= nums.size()) return true;
        if(dp[i] != -1) return dp[i];
        bool ans = false;
        if(i < nums.size()-1 and nums[i] == nums[i+1]){
            ans = solve(i+2,nums,dp);
        }
        if(ans == true) return dp[i] = true;
        if(i < nums.size()-2 and nums[i] == nums[i+1] and nums[i+1] == nums[i+2]){
            ans = solve(i+3,nums,dp);
        }
        if(ans == true) return dp[i] = true;
        if(i < nums.size()-2 and (nums[i+2] - nums[i+1] == 1) and (nums[i+1] - nums[i] == 1)){
            ans = solve(i+3,nums,dp);
        }
        if(ans == true) return dp[i] = true;
        return dp[i] = ans;
    }
    bool validPartition(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};