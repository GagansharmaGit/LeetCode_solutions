class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last_index(26,-1);
        vector<int>taken(26,false);
        string ans = "";
        for(int i=0;i<s.length();i++){
            last_index[s[i] - 'a'] = i;
        }

        for(int i=0;i<s.length();i++){
            if(taken[s[i]-'a'] == true){
                continue;
            }
            while(ans.length() > 0 and ans.back() > s[i] and last_index[ans.back()-'a'] > i){
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            taken[s[i] - 'a'] = true;
            ans += s[i];
        }
        return ans;
    }
};