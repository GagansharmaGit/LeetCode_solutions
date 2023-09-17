class Solution {
public:
    map<pair<int,int>,int>mp;
    int solve(int i,int prev,vector<int>&arr1,vector<int>&arr2){
        if(i >= arr1.size()) return 0;
        if(mp.find({i,prev}) != mp.end()) return mp[{i,prev}];
        int ans1 = 1e9+1;
        if(arr1[i] > prev){
            ans1 = solve(i+1,arr1[i],arr1,arr2);
        }
        int ans2 = 1e9+1;
        auto it = upper_bound(begin(arr2),end(arr2),prev);
        if(it != end(arr2)){
            int ind = it - begin(arr2);
             ans2 = 1 + solve(i+1,arr2[ind],arr1,arr2);
        }
        return mp[{i,prev}] = min(ans1,ans2);
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        mp.clear();
        int prev = INT_MIN;
        int res = solve(0,prev,arr1,arr2);
        if(res == 1e9+1){
            return -1;
        }
        return res;
    }
};