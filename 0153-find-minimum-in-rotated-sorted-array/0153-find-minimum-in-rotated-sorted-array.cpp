class Solution {
public:
    int findMin(vector<int>& arr) {
        int ans =INT_MAX;
        int start = 0;
        int end = arr.size() - 1;
        while(start <= end){
            int mid = (start + (end - start) / 2);
            if(arr[start] <= arr[end]){
                ans = min(ans,arr[start]);
                break;
            }
            if(arr[start] <= arr[mid]){
                ans = min(ans,arr[start]);
                start = mid + 1;
            }else{
                ans = min(ans,arr[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};