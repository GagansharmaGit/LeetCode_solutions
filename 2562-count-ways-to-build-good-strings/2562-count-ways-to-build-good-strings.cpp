class Solution {
public:
    int l;
    int h;
    int z;
    int o;
    int mod = 1e9+7;
    int  solve(int currLen,vector<int>&dp){
        if(currLen > h) return 0;
        if(dp[currLen] != -1) return dp[currLen];
        int add = 0;
        if(currLen >= l and currLen <= h) add = 1;
        int add_zero = solve(currLen+z,dp) ;
        int add_one = solve(currLen+o,dp);
        return dp[currLen] = (add + add_zero + add_one) %mod;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        z=zero;
        o=one;
        int currLen = 0;
        vector<int>dp(high+1,-1);
        return solve(currLen,dp);
    }
};