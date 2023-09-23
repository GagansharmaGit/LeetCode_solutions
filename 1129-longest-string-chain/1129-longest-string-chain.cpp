class Solution {
public:
bool check(string &s1,string &s2){
    if(s1.length() != s2.length()+1){
        return false;
    }
    int i=0;
    int j=0;
    while(i < s1.length()){
        if(i <s1.length() and j < s2.length() and s1[i] == s2[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i == s1.length() and j == s2.length()){
        return true;
    }
    return false;
}
    
    static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),comp);
        int maxi=1;
        vector<int>dp(words.size()+1,1);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) and 1+dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};