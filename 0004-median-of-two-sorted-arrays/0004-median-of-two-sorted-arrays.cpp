class Solution {
public:
    double median(vector<int>&arr1,vector<int>&arr2){
        int n1 = arr1.size();
        int n2 = arr2.size();
        int total_size = n1 + n2;
        int low = 0;
        int high = n1;
        int left_half = (n1 + n2 + 1) / 2;
        while(low <= high){
            int mid1 = (low + high)>>1;
            int mid2 = left_half - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN; 
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1 < n1) r1 = arr1[mid1];
            if(mid2 < n2) r2 = arr2[mid2];
            if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
            if(l1 <= r2 and l2 <= r1){
                if(total_size % 2 == 1){
                    return max(l1,l2);
                }else{
                    return ((double)(max(l1,l2) + min(r1,r2)))/ 2.0;
                }
            }else if(l1 > r2) high = mid1 - 1;
            else{
                low = mid1 + 1;
            }
        }
        return 0; // this is dummy statement which will never execute
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 <= n2) return median(nums1,nums2);
        else return median(nums2,nums1);
    }
};