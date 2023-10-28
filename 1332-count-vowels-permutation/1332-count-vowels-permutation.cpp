class Solution {
public:
 long long
    
    int a=0,e=1,i=2,o=3,u=4;
    int M =1e9+7;
    long long solve(int vowel,int n,vector<vector<long long>>&dp){
        if(n == 0){
            return 1;
        }

        if(dp[vowel][n] != -1) return dp[vowel][n];
        
        
        if(vowel == a){
            return dp[vowel][n] = solve(e, n-1,dp) % M;
        }else if(vowel == e){
            return dp[vowel][n] = (solve(a, n-1,dp) + solve(i, n-1,dp)) % M;
        }else if(vowel == i){
            return dp[vowel][n] = (solve(a, n-1,dp) + solve(e, n-1,dp) + solve(o, n-1,dp) + solve(u, n-1,dp)) % M;
        }else if(vowel == o){
            return dp[vowel][n] = (solve(i, n-1,dp) + solve(u, n-1,dp)) % M;
        }else{
            return dp[vowel][n] = solve(a, n-1,dp);
        }

        
    }
    int countVowelPermutation(int n) {

        vector<vector<long long>>dp(5,vector<long long>(n+1,-1));
        if(n == 1) return 5;
        long long ans = 0;
        ans = (ans + solve(a,n-1,dp))% M;
        ans = (ans + solve(e,n-1,dp))% M;
        ans = (ans + solve(i,n-1,dp))% M;
        ans = (ans + solve(o,n-1,dp))% M;
        ans = (ans + solve(u,n-1,dp))% M;

        return ans;
    }
};