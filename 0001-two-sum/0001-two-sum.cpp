class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()){
                ans.emplace_back(i);
                ans.emplace_back(m[target-nums[i]]);
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};