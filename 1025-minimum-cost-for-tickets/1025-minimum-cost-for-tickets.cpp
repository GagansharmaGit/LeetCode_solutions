class Solution {
public:
    int solve(int i,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        //for cost[0]
        int cost_2 = costs[0] + solve(i+1,days,costs,dp);
        //for 7 day cost
        int passenger_day_7 = days[i]+7-1;
        int j=i;
        while(j<days.size() and days[j] <= passenger_day_7){
            j++;
        }
        int cost_7 = costs[1] + solve(j,days,costs,dp);
        //for_30 days ticket price
        int passenger_day_30 = days[i] +30-1;
        int k=i;
        while(k<days.size() and days[k] <= passenger_day_30){
            k++;
        }
        int cost_30 = costs[2] + solve(k,days,costs,dp);

        return dp[i] = min(cost_2,min(cost_7,cost_30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(0,days,costs,dp);
    }
};