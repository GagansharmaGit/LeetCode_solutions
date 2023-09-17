class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>direction={{-1,0},{0,-1},{0,1},{1,0}};
    bool is_safe(int i,int j,vector<vector<int>>&grid){
        return (i>=0 and i < grid.size() and j >= 0 and j < grid[0].size());
    }
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int ans = 1;
        if(dp[i][j] != -1) return dp[i][j];
        for(auto dir:direction){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(is_safe(new_i,new_j,grid) and grid[new_i][new_j] < grid[i][j]){
                ans += (solve(new_i,new_j,grid,dp))%mod;
            }
        }
        return dp[i][j] = (ans)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = (result + solve(i,j,grid,dp))%mod;
            }
        }
        return result%mod;
        
    }
};