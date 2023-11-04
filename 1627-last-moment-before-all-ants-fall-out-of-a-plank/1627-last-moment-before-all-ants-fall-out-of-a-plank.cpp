class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {

        int result = 0;
        int result2 = 0;
        for(int &x : left) {
            result = max(x, result);
        }
        
        for(int &x : right) {
            result2 = max(result2, n-x);
        }
        
        return max(result,result2);
    }
    
};