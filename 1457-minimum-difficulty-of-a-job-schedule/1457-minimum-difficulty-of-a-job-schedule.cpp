class Solution {
public:
    int solve(int i,vector<int>&job,int d,vector<vector<int>>&dp){
        if(d == 1){ // base case
            // it means if i have only one day left then i have to do all the jobs which is present in the array from i to end. So, the max elem from them is my ans.
            int maxi = INT_MIN;
            for(int j=i;j<job.size();j++){
                maxi = max(maxi,job[j]);
            }
            return maxi;
        }
        if(dp[i][d] != -1) return dp[i][d];
        int result = INT_MAX;
        int maxii = INT_MIN;
        for(int a=i;a<=job.size()-d;a++){
             maxii = max(maxii,job[a]);
            // int tempans = maxii + solve(a+1,job,d);
            result = min(result,maxii + solve(a+1,job,d-1,dp));
        }
        return dp[i][d] = result;
    }
    int minDifficulty(vector<int>& job, int d) {
        vector<vector<int>>dp(job.size()+1,vector<int>(d+1,-1));
        if(job.size()<d) return -1;
        return solve(0,job,d,dp);
    }
};