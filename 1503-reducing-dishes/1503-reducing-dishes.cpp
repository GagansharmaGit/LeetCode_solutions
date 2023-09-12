class Solution {
public:
// if cook prepare the current meal the its sum will be satis[i] * time
    int solve(int i,int time,vector<int>&satis,vector<vector<int>>&dp){
        if(i >= satis.size()) return 0; // now i can cook anything
        if(dp[i][time] != -1) return dp[i][time];
        // take (cook the current satis[i] food)
        int take = (satis[i] * time) + solve(i+1,time+1,satis,dp);
        // do not take (cook is not cooking the current food, so time will not increase)
        int not_take = solve(i+1,time,satis,dp);
        return dp[i][time] = max(take,not_take);
    }
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        vector<vector<int>>dp(satis.size()+1,vector<int>(satis.size()+2,-1));
        return solve(0,1,satis,dp);
    }
};