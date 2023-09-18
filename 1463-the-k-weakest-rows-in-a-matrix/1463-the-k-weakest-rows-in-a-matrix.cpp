class Solution {
public:
    int binarySearch(vector<int>&temp,int a,int b){
        int count = -1;
        int l = a;
        int h = b;
        int mid;
        while(l <= h){
             mid = l + (h-l)/2;
            if(temp[mid] == 1){
                count = mid;
                l = mid + 1;
            }else if(temp[mid] == 0){
                h = mid - 1;
            }
        }
        return count+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int,int>>pq;
        for(int row = 0;row<m;row++){
            int ones_count = binarySearch(mat[row],0,n-1);
            pq.push({ones_count,row});
            if(pq.size() > k) pq.pop();
        }
        vector<int>ans(k);
        int i = k-1;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ans[i--] = temp.second;
        }
        return ans;
    }
};