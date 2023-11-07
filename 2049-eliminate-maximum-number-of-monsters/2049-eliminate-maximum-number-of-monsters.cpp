class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>time(dist.size());
        for(int i=0;i<dist.size();i++){
            time[i] = ceil((float)dist[i]/speed[i]);
        
        }
        sort(begin(time),end(time));
        int count = 1; // count will always start from 1 because dist will never start with 0 then we can kill atleast one monster every time
        int time_pass = 1;
        for(int i=1;i<time.size();i++){
            if(time[i] - time_pass <= 0) return count;
            count++;
            time_pass += 1;
        }

        return count;
    }
};