class Solution {
public:
    int myAtoi(string s) {
        // string s1="";
        int i=0;
        while(i<s.size() and s[i]==' '){
            i++;
        }
        // s1=s.substr(i);
       int count1=0;
       if(s[i] == '-'){
           count1++;
           i++;
       }
       int count2=0;
       if(s[i] == '+'){
           count2++;
           i++;
       }

       double ans=0;
       while(i<s.size() and s[i] >= '0' and s[i] <= '9'){
           ans=ans*10+(s[i] - '0');
           i++;
       }
       if(count1 > 0){
           ans=-ans;
       }
       if(count1 > 0 and count2 >0){
           return 0;
       }

       if(ans > INT_MAX){
          ans= INT_MAX;
       }
       if(ans < INT_MIN){
           ans= INT_MIN;
       }

        
        return (int)ans;

        
    }
};