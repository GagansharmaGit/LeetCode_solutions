class Solution {
public:
    vector<pair<int,int>>directions = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    double solve(int row,int col,int k,int &n,vector<vector<vector<double>>>&dp){
        if(row < 0 or row >= n or col < 0 or col >=n) return 0;
        if(k == 0) return 1;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        double ans = 0;
        for(auto dir:directions){
            int new_row = row + dir.first;
            int new_col = col + dir.second;
            ans += (double)solve(new_row,new_col,k-1,n,dp);
        }
        return dp[row][col][k] = (double)ans /(8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return solve(row,column,k,n,dp);
    }
};