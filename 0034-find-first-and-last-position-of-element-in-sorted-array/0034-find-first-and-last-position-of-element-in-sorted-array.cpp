class Solution {
public:
    int firstOcc(vector<int>&nums,int &target,int &size){
        int start = 0;
        int end = size -1;
        int ind = -1;
        while(start <= end){
            int mid = (start+end) /2;

            if(nums[mid] == target){
                ind = mid;
                start = mid + 1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ind;
    }


    int secOcc(vector<int>&nums,int &target,int &size){
        int start = 0;
        int end = size -1;
        int ind = -1;
        while(start <= end){
            int mid = (start + end) /2;
            if(nums[mid] == target){
                ind = mid;
                end = mid -1;
            }else if(nums[mid] > target){
                end = mid -1;
            }else{
                start = mid +1;
            }
        }
        return ind;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int first = firstOcc(nums,target,size);
        int second = secOcc(nums,target,size);

        return {second,first};
        // return {first,second};
    }
};