class Solution {
public:
    string decodeAtIndex(string s, int k){
        long long size = 0;
        for(char i:s){
            if(isalpha(i)){
                size += 1;
            }else{
                size = size * (i-'0');
            }
        }
        cout<<size;
        for(int i=s.length()-1;i>=0;i--){
            k = k%size;
            if(k == 0 and isalpha(s[i])){
                return string(1,s[i]);
            }
            if(isalpha(s[i])){
               size-=1;
            }else{
                 size = size/(s[i]-'0');
            }
        }
        return "";
    }
};