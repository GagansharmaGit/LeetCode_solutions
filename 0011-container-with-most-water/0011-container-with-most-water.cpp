class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int i = 0;
        int j = height.size()-1;
        
        while(i<j){
            int width = j-i;
            int currHeight = min(height[i],height[j]);
            int currWater = width*currHeight;
            maxWater = max(maxWater,currWater);

            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxWater;
    }
};