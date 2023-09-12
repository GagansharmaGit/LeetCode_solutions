class Solution {
public:
    int solve(int i,int prev,string &s,vector<vector<int>>&dp){
        if(i >= s.length()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int flip = INT_MAX;
        int not_flip = INT_MAX;
        if(s[i] == '0'){
            if(prev == 0){
                flip = 1 + solve(i+1,1,s,dp);
                not_flip = solve(i+1,0,s,dp);
            }else if(prev == 1){
                flip = 1 + solve(i+1,1,s,dp);
            }
        }else if(s[i] == '1'){
            if(prev == 0){
                flip = 1 + solve(i+1,0,s,dp);
                not_flip = solve(i+1,1,s,dp);
            }else if(prev == 1){
                not_flip = solve(i+1,1,s,dp);
            }
        }
        return dp[i][prev] = min(flip,not_flip);
    }
    int minFlipsMonoIncr(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(2,-1));
        int prev = 0;
        return solve(0,prev,s,dp);
    }
};