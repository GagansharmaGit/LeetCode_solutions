class Solution {
public:
    char findTheDifference(string s, string t) {
        int XOR = 0;
        for(auto &ch:s){
            XOR = XOR^ch;
        }
        for(auto &ch:t){
            XOR = XOR^ch;
        }
        return (char)XOR;
    }
};