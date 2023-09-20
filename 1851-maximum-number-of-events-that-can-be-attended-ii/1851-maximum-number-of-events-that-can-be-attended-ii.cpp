class Solution {
public:
    int solve(int i,int k,vector<vector<int>>&events,vector<vector<int>>&dp){
        if(k <= 0 or i >= events.size()) return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int not_take = solve(i+1,k,events,dp);

        int start = events[i][0];
        int end = events[i][1];
        int taken_val = events[i][2];
        vector<int>temp = {end,INT_MAX,INT_MAX};
        int next_taken_ind = upper_bound(events.begin(),events.end(),temp) - events.begin();
        int take = taken_val + solve(next_taken_ind ,k-1,events,dp);
        return dp[i][k] = max(take,not_take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>>dp(events.size()+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return solve(0,k,events,dp);
    }
};