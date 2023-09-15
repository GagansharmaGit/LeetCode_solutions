class Solution {
public:
    long long solve(int i,vector<vector<int>>&ques,vector<long long>&dp){
        if(i >= ques.size()) return 0;
        if(dp[i] != -1) return dp[i];
        long long not_taken = 0 + solve(i+1,ques,dp);
        long long taken = ques[i][0] + solve(i+1+ques[i][1],ques,dp);
        return dp[i] = max(taken,not_taken);
    }
    long long mostPoints(vector<vector<int>>& ques) {
        vector<long long>dp(ques.size()+1,-1);
        return solve(0,ques,dp);
    }
};