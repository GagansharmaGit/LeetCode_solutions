class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>left_to_right_sum(nums.size());
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp += nums[i];
            left_to_right_sum[i]= temp;
        }
        for(auto i:left_to_right_sum){
            cout<<i<<" ";
        }

        
        vector<int>right_to_left_sum(nums.size());
        temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            temp +=nums[i];
            right_to_left_sum[i]= temp;
        }
        for(auto i:right_to_left_sum){
            cout<<i<<" ";
        }

        for(int i=0;i<nums.size();i++){
            if(right_to_left_sum[i] == left_to_right_sum[i]){
                return i;
            }
        }

        return -1;
        
    }
};