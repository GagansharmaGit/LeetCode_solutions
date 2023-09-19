class Solution {
public:
    int solve(int i,int diff,vector<int>&rods,vector<vector<int>>&dp){
        if(i >= rods.size()){
            if(diff == 0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][5000+diff] != -1) return dp[i][5000+diff];
        int ans1 = solve(i+1,diff,rods,dp);
        int ans2 = rods[i] + solve(i+1,diff+rods[i],rods,dp);
        int ans3 = rods[i] + solve(i+1,diff-rods[i],rods,dp);
        return dp[i][5000+diff] = max(ans1,max(ans2,ans3));
    }
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int diff = 0;
        vector<vector<int>>dp(rods.size()+1,vector<int>(10000,-1));
        return solve(0,diff,rods,dp)/2;
    }
};