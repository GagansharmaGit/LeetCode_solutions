class Solution {
public:
    void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
        int i=m-1;
        int j=n-1;
        while(i>=0 and j>=0){
            if(n1[i] > n2[j]){
                n1[i+j+1]=n1[i];
                i--;
            }else{
                n1[i+j+1]=n2[j];
                j--;
            }
        }
        while(j>=0){
            n1[j]=n2[j];
            j--;
        }

    }
};