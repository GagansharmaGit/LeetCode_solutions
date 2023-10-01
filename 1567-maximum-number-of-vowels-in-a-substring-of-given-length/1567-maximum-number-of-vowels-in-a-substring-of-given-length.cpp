class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int count = 0;
        int j=0;
        int i=0;
        while(j < s.length()){
            if(isVowel(s[j])){
                count++;
            }
            if(j - i + 1 == k){
                ans = max(ans,count);
                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};