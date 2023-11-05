class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int count = 0;
        int n=arr.size();
        if(k >= n) return *max_element(begin(arr),end(arr));
        for(int i=1;i<n;i++){
            if(arr[i] > winner){
                winner = arr[i];
                count = 1;
                arr.push_back(winner);
            }else{
                count++;
                arr.push_back(arr[i]);
                if(count == k) return winner;
            }
            if(count == k) return winner;
            n=arr.size();
        }

        return -1;
    }
};