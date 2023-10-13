class Solution {
public:
    int top(int i,vector<int>&cost,int n,vector<int>&dp){
        if( i < 2){
            return cost[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }

       
        int ans = cost[i] + min(top(i-1,cost,n,dp) , top(i-2,cost,n,dp));

        return dp[i] = ans; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return min(top(cost.size()-1,cost,n,dp) , top(cost.size()-2,cost,n,dp));
        
    }
};