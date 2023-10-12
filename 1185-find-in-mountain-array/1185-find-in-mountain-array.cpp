/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int getpeakindex(MountainArray &mountainArr,int n){
        int mid;
        int l = 0;
        int r = n-1;
        while(l < r){
            mid = l + (r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
    }
    int binarysearch(MountainArray &mountainArr,int l,int r,int target){
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
           if(mountainArr.get(mid) == target){
                 return mid;
            }
            if(mountainArr.get(mid) < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
    int reversebinary(MountainArray &mountainArr,int l,int r,int target){
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(mountainArr.get(mid) == target){
                 return mid;
            }
            if(mountainArr.get(mid) > target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int ind = getpeakindex(mountainArr,n);
        int ans = binarysearch(mountainArr,0,ind,target);
        if(ans != -1) return ans;

        return reversebinary(mountainArr,ind+1,n-1,target);
    }
};