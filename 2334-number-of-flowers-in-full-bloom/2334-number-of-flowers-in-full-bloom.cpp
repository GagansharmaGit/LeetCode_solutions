class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();

        vector<int>start_time(n);
        vector<int>end_time(n);
        for(int i=0;i<n;i++){
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        vector<int>result(m);

        for(int i=0;i<m;i++){

            int arrive_time = people[i];

            int bloom_already = upper_bound(begin(start_time), end(start_time), arrive_time) - begin(start_time);
            
            int died_already = lower_bound(begin(end_time), end(end_time), people[i]) - begin(end_time);

            result[i] = bloom_already - died_already;

        }
        return result;
    }
};