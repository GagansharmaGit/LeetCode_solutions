class Solution {
public:
    int top(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i >= s.length()){
            return 0;
        }
        if(j >= t.length() ){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }


        if(s[i] == t[j]){
            
            return dp[i][j] = 1 + top(i+1,j+1,s,t,dp);
        }else{
        return dp[i][j] = top(i,j+1,s,t,dp);

        }

    }
   
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
       if(s.length() == top(0,0,s,t,dp)){
           return true;
       }
       return false;
    }
};