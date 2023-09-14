class Solution {
public:
    int solve(int i,vector<vector<int>>&piles,int k,vector<vector<int>>&dp){
      if(i >= piles.size()) return 0;
      
      if(dp[i][k] != -1) return dp[i][k];
      int not_taken = solve(i+1,piles,k,dp);

      int taken = 0;
      int sum = 0;
      for(int j=0;j<piles[i].size();j++){
        sum += piles[i][j];
        if(k-(j+1) >= 0)
           taken = max(taken , sum + solve(i+1,piles,k-(j+1),dp));
      }
      return dp[i][k] = max(not_taken,taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(k+1,-1));
        return solve(0,piles,k,dp);
    }
};