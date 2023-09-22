class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }

        int count = 0;
        for(auto word:words){
            int prev = -1;
            bool found = true;
            for(auto ch:word){
                if(mp.find(ch) == mp.end()){
                    found = false;
                    break;
                }
                auto it = upper_bound(mp[ch].begin(),mp[ch].end(),prev);
                if(it == mp[ch].end()){
                    found = false;
                    break;
                }
                prev = *it;
            }
            if(found == true) count++;
        }
        return count;
    }
};