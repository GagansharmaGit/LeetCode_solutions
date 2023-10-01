class Solution {
public:
   // we can solve it using string stream( have to learn after this wuestion)
    string reverseWords(string s) {
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i] != ' '){
                j = i;
                while(j <s.length() and s[j] != ' '){
                    j++;
                }
                reverse(s.begin()+i,s.begin()+j);
                i=j;
            }
        }
        return s;
    }
};