class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(256,-1);
        int left=0;
        int right=0;
        int len=0;
        while(right<s.size()){
            if(v[s[right]] != -1){
                left=max(v[s[right]]+1,left);
            }
            v[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
        
    }
};