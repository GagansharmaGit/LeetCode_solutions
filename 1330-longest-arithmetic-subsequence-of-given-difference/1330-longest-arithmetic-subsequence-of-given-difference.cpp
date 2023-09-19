class Solution {
public:
    int solve(int i,int prev_val_ind,int diff,vector<int>&arr,vector<vector<int>>&dp){
        if(i >= arr.size()) return 0;
        if(dp[i][prev_val_ind] != -1) return dp[i][prev_val_ind];
        int curr_val = arr[i];
        int prev_val = arr[prev_val_ind];
        int ans = 0;
        if(curr_val - prev_val == diff){
            ans = max(ans,1 + solve(i+1,i,diff,arr,dp));
        }else{
            ans = max(ans,solve(i+1,prev_val_ind,diff,arr,dp));
        }
        return dp[i][prev_val_ind] = ans;
    }
    int longestSubsequence(vector<int>& arr, int diff) {
        // int n = arr.size();
        // int maxi = INT_MIN;
        // vector<vector<int>>dp(arr.size()+1,vector<int>(arr.size()+1,-1));
        // for(int i=0;i<n;i++){
        //     maxi = max(maxi,1+solve(i+1,i,diff,arr,dp));
        // }
        // return maxi;
        // ````````````````````````````` This above solution gives memory limit out`````````````````````````````````

        int n = arr.size();
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int prev = arr[i] - diff;
            int len = mp[prev] + 1;
            mp[arr[i]] = len;
            maxi = max(maxi,mp[arr[i]]);
        }
        return maxi;
    }
};