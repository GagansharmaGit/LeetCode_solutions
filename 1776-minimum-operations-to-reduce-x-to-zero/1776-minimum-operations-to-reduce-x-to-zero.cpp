class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0] = -1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x) return -1;
        int restsum = sum-x;
        sum = 0;
        int longest_sum_subarray = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int findsum = sum - restsum;
            if(mp.find(findsum) != mp.end()){
                longest_sum_subarray = max(longest_sum_subarray,i - mp[findsum]);
            }
        }
        if(longest_sum_subarray == INT_MIN) return -1;
        return nums.size() - longest_sum_subarray;
    }
};