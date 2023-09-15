class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>lis;
        vector<int>ans(obstacles.size(),1);
        for(int i=0;i<obstacles.size();i++){
            int ind = upper_bound(begin(lis),end(lis),obstacles[i]) - begin(lis);
            if(ind == lis.size()){
                lis.push_back(obstacles[i]);
            }else{
                lis[ind] = obstacles[i];
                //ind+1 is equal to length of longest increasing subsequence
            }
            ans[i] = ind+1;
        }
        return ans;
    }
};