class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,string &s,int &k,vector<int>&dp){
        if(i >= s.length()){
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        long int num = 0;
        long long ans = 0;
        if(s[i] == '0') return 0;
        for(int j=i;j<s.length();j++){
            num = (num*10) + (s[j]-'0');
            if(num > k) break;
            ans += (solve(j+1,s,k,dp))%mod;
        }
        return dp[i] = (ans)%mod;
    }
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,k,dp);
    }
};