class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1e9 + 7;
        sort(begin(arr),end(arr));
        unordered_map<int,long long>mp;
        for(auto i:arr){
            mp[i] = 1;
        }

        for(int i=0;i<arr.size();i++){
            int root = arr[i];
            for(int j=0;j<i;j++){
                int left_child = arr[j];
                int right_child = root/left_child;
                if(root%left_child == 0 and mp.find(right_child) != mp.end()){
                    mp[root] += mp[left_child] * mp[right_child];
                }
            }
        }

        int result = 0;
        for(auto i:mp){
            result = (result + i.second) % MOD;
        }
        return result;
    }
};