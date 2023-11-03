class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;

        int i=0;
        int stream = 1;

        while(i < target.size() and stream <= n){
            if(stream == target[i]){
                ans.push_back("Push");
                i++;
                stream++;
            }else if(stream != target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                stream++;
            }
        }
        return ans;
    }
};