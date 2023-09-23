class Solution {
public:
    vector<pair<int,int>>operations {{100,0} , {75,25} , {50,50} , {25,75}};
    double solve(double A,double B,vector<vector<double>>&dp){
        if(A <= 0 and B <= 0) return (double)1.0/(double)2.0;
        if(A <= 0) return 1.0;
        if(B <= 0) return 0.0;
        if(dp[A][B] != -1) return dp[A][B];
        double prob = 0.0;
        for(auto op:operations){
            double new_A =  op.first;
            double new_B =  op.second;
            prob += solve(A - new_A , B - new_B,dp);
        }
        return dp[A][B] = 0.25 * prob;
    }
    double soupServings(int n) {
        if(n >= 5000) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,dp);
    }
};