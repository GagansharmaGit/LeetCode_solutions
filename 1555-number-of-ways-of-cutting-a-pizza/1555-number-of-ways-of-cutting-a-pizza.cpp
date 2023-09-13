class Solution {
public:
    int m;
    int n;
    int M = 1e9+7;
    int solve(int i,int j,int k,vector<string>&pizza,vector<vector<int>>&apples,vector<vector<vector<int>>>&dp){
        if(apples[i][j] < k ){
            return 0;
        }
        if(k == 1){
            if(apples[i][j] >= 1){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int h_cuts = 0;
        for(int h =i+1;h<m;h++){
            int lower_pieces = apples[h][j];
            int upper_pieces = apples[i][j] - lower_pieces;
            if(lower_pieces >= k-1 and upper_pieces >= 1){
                h_cuts = (h_cuts%M + solve(h,j,k-1,pizza,apples,dp)%M)%M;
            }
            
        }

        int v_cuts = 0;
        for(int v = j+1;v<n;v++){
            int right_pieces = apples[i][v];
            int left_pieces = apples[i][j] - right_pieces;
            if(right_pieces >= k-1 and left_pieces >= 1){
                v_cuts = (v_cuts%M + solve(i,v,k-1,pizza,apples,dp));
            }
        }

        return dp[i][j][k] = h_cuts + v_cuts;

    }
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>>apples(55,vector<int>(55,0));
        m=pizza.size();
        n=pizza[0].length();
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                apples[i][j] = apples[i][j+1];
                for(int l=i;l<m;l++){
                    if(pizza[l][j] == 'A'){
                        apples[i][j]++;
                    }
                }
            }
        }
        vector<vector<vector<int>>>dp(50,vector<vector<int>>(50,vector<int>(50,-1)));
        return solve(0,0,k,pizza,apples,dp);
    }
};