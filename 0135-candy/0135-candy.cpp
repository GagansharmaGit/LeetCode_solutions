class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candies1(ratings.size(),1);
        vector<int>candies2(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i] > ratings[i-1]){
                candies1[i] = candies1[i-1] + 1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                candies2[i] = candies2[i+1]+1;
            }
        }
        int min_can_req = 0;
        for(int i=0;i<candies1.size();i++){
            min_can_req += max(candies1[i],candies2[i]);
        }
        return min_can_req;
    }
};