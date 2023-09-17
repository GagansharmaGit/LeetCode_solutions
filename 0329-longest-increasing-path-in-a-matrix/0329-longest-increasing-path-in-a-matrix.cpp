class Solution {
public:
    vector<vector<int>>direction={{-1,0},
                     {0,-1},       {0,1},
                            {1,0}};
    bool is_safe(int i,int j,vector<vector<int>>&matrix){
        if(i >=0 and i < matrix.size() and j >= 0 and j < matrix[0].size()){
            return true;
        }else{
            return false;
        }
    }
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int ans = 1;
        int temp = 1;
        if(dp[i][j] != -1) return dp[i][j];
        for(auto dir:direction){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(is_safe(new_i,new_j,matrix) and matrix[new_i][new_j] < matrix[i][j]){
                ans = 1 + solve(new_i,new_j,matrix,dp);
                temp = max(temp,ans);
            }

        }
        return dp[i][j] = temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi = INT_MIN;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi = max(maxi,solve(i,j,matrix,dp));
            }
        }
        return maxi;
    }
};