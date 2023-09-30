class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Brute Force A1
        // for(int i=0;i<nums.size()-2;i++){
        //   for(int j=i+1;j<nums.size()-1;j++){
        //     if(nums[i] < nums[j] and i < j){
        //       for(int k=j+1;k<nums.size();k++){
        //         if(nums[i] < nums[k] and nums[k] < nums[j]){
        //           return true;
        //         }
        //       }
        //     }
        //   }
        // }
        // return false;


        //Brute Force A2
        // int n = nums.size();
        // int mini_i = INT_MAX;
        // for(int j=0;j<n-1;j++){
        //   mini_i = min(mini_i,nums[j]);
        //     for(int k=j+1;k<n;k++){
        //       if(mini_i < nums[k] and nums[k] < nums[j]){
        //         return true;
        //       }
        //     }
          
        // }
        // return false;



        // Best Approach
        //using monotic stack

        stack<int>st;
        int n = nums.size();
        int nums3 = INT_MIN;
        for(int i=n-1;i>=0;i--){
          if(nums[i] < nums3){
            return true;
          }
         
          while(!st.empty() and nums[i] > st.top()){
            nums3 = st.top();
            st.pop();
          }
          st.push(nums[i]);

        }
        return false;
    }
};