class Solution {
public:
    int mod = 1000000007;
    int solve(int i,int search_cost_k,int maxi,int &n,int &m,int &k,vector<vector<vector<int>>>&dp){
        if(i == n){
            if(search_cost_k == k) return 1;
            else return 0;
        }
        if(dp[i][search_cost_k][maxi] != -1){
            return dp[i][search_cost_k][maxi];
        }
        int ans = 0;
        for(int ind = 1; ind <= m; ind++){
            if(ind > maxi){
                ans = (ans + solve(i+1 , search_cost_k+1 , ind , n , m , k , dp)) % mod;
            }else{
                ans = (ans + solve(i+1 , search_cost_k , maxi , n , m , k , dp)) % mod;
            }
        }
        // return dp[i][search_cost_k][maxi] = (ans) % mod;
        return dp[i][search_cost_k][maxi] = (ans) % mod;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(60,vector<vector<int>>(60,vector<int>(110,-1)));
        int search_cost_k = 0;
        int maxi = 0;
        // memset(dp2,-1,sizeof(dp2));
        return solve(0,search_cost_k,maxi,n,m,k,dp);
    }
};