class Solution {
public:
    int find_1bit_count(int num){
        int count = 0;
        while(num != 0){
            int a = (num & 1);
            if(a == 1){
                count++;
            }

            num = (num >> 1);
        }
        return count;
    }
    
    vector<int> sortByBits(vector<int>& arr) {


        auto lambda = [&](int &a,int &b){
            int count_1 = find_1bit_count(a);
            int count_2 = find_1bit_count(b);
            if(count_1 == count_2){
                return a<b;//return smallest number between a and b
            }

            return count_1 < count_2; //returning the smallest bit count variable
        };


        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};