class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int>arr;
        arr.push_back(1);
        for(int i=0;i<rowIndex;i++){
            ans = ans*(rowIndex - i);
            ans = ans/(i+1);
            arr.push_back(ans);
        }
        return arr;
    }
};