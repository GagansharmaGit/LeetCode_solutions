class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp;
        for(auto match:matches){
            mp[match[1]]++;
        }
        vector<int>not_loose;
        vector<int>once_loose;
        for(auto match:matches){
            int win = match[0];
            int loose = match[1];
            if(mp.find(win) == mp.end()){
                not_loose.push_back(match[0]);
                mp[match[0]] = INT_MAX;
            }
            if(mp[loose] == 1){
                once_loose.push_back(loose);
            }
        }
        sort(begin(not_loose),end(not_loose));
        sort(begin(once_loose),end(once_loose));

        return {not_loose , once_loose};
    }
};