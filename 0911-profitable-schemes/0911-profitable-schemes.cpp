class Solution {
public:
    int thres;
    int N;
    int mod = 1e9+7;
    int solve(int i,int people,int total_profit,vector<int>&group,vector<int>&profit,vector<vector<vector<int>>>&dp){
        if(i >= group.size()){
            if(total_profit >= thres){
                return 1;
            }
            return false;
        }
        if(dp[i][people][total_profit] != -1) return dp[i][people][total_profit];
        long long not_taken = solve(i+1,people,total_profit,group,profit,dp)%mod;
        long long taken = 0;

        if(people + group[i] <= N){
            taken = solve(i+1,people+group[i],min(thres,total_profit + profit[i]),group,profit,dp)%mod;
        }

        return dp[i][people][total_profit] = (taken + not_taken)%mod;
    }
    int profitableSchemes(int n, int minprofit, vector<int>& group, vector<int>& profit) {
        int people=0;
        int ind=0;
        int total_profit = 0;
        thres = minprofit;
        N = n;
        vector<vector<vector<int>>>dp(group.size()+1,vector<vector<int>>(101,vector<int>(301,-1)));
        return solve(ind,people,total_profit,group,profit,dp);
    }
};