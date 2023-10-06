class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>v(2001,0);
        for(int i=0;i<arr.size();i++){
            v[1000 + arr[i]]++;
        }
        sort(begin(v),end(v));
        for(int i=0;i<v.size()-1;i++){
            if(v[i] == 0) continue;
            if(v[i] == v[i+1]){
                return false;
            }
        }
        return true;
    }
};