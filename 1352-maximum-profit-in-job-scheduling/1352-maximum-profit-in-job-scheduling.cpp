class Solution {
public:
    int index(int i,vector<vector<int>>&ans,int find){
        int res = -1;
        int low = i;
        int end = ans.size()-1;
        while(low <= end){
            int mid = low + (end - low) / 2;
            if(ans[mid][0] >= find){
                res = mid;
                end = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
    int solve(int i,vector<vector<int>>&ans,vector<int>&dp){
        if(i>=ans.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int greater_ind = index(i+1,ans,ans[i][1]);
        int maxi = INT_MIN;
        //take 
        int ans1 = ans[i][2] + solve(greater_ind,ans,dp);
        //not take
        int ans2 = solve(i+1,ans,dp);
        maxi = max(ans1,ans2);
        return dp[i] = maxi;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>ans(startTime.size(),vector<int>(3,0));
        for(int i=0;i<startTime.size();i++){
            ans[i][0]=startTime[i];
            ans[i][1]=endTime[i];
            ans[i][2]=profit[i];        
        }
        sort(ans.begin(),ans.end());
        vector<int>dp(startTime.size()+1,-1);
        return solve(0,ans,dp);
    }
};