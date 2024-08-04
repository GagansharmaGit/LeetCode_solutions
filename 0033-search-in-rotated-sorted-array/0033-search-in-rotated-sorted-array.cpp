class Solution {
public:
    int search(vector<int>& nu, int target) {
        int start=0;
        int n=nu.size();
        int end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nu[mid]==target){
                return mid;
            }
            //is left part sorted?
            if(nu[start]<=nu[mid]){
                if(nu[start]<=target and target <=nu[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //is target present between right part?
                if(nu[mid]<=target and target <=nu[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};