class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>st;
        for(int i=0;i<days.size();i++){
            st.insert(days[i]);
        }
        vector<int>dp(days.back()+1,0);
        dp[0] = 0;
        int last_day = days.back();
        for(int i = 1;i<=last_day;i++){
            if(st.find(i) == st.end()){
                dp[i] = dp[i-1]; //skipping the day which we do not have to travel so we just copt the result of prev state
                continue;
            }
            int pass_1_cost = costs[0] + dp[max(i-1,0)];
            int pass_7_cost = costs[1] + dp[max(i-7,0)];
            int pass_30_cost = costs[2] + dp[max(i-30,0)];
            dp[i] = min(pass_1_cost,min(pass_7_cost,pass_30_cost));
        }
        return dp[last_day];
    }
};