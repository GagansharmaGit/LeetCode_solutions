class Solution {
public:
    bool allzeros(vector<int>&count){
        for(auto i:count){
            if(i != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>count(26,0);
        for(int i=0;i<p.length();i++){
            count[p[i]-'a']++;
        }
        vector<int>result;
        int i=0;
        int j=0;
        while(j<s.length()){
            int ch = s[j]-'a';
            count[ch]--;
            if(j-i+1==p.length()){
                if(allzeros(count) == true){
                    result.push_back(i);
                }
                count[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
        
    }
};