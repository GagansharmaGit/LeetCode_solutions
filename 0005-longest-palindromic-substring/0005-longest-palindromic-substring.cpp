class Solution {
public:
bool ispalindrome(string &s,int i,int j){
    while(i < j){
        if(s[i]!=s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(ispalindrome(s,i,j)){
                string t=s.substr(i , j-i+1);
                if(t.size() > ans.size()){
                    ans=t;
                }
                }
            }
        }
        return ans;
    }
};