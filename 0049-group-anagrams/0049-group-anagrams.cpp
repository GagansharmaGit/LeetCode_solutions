class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string,vector<string> > mp;
    for(auto i:strs){
        string temp=i;
        sort(i.begin(),i.end());
        mp[i].push_back(temp);
        
    }
    for(auto j:mp){
        ans.push_back(j.second);
    }
    return ans;
        
    }
};