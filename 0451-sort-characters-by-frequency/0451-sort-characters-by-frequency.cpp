class Solution {
public:
    typedef pair<char, int> P;
    struct lamda{
        bool operator()(P &a , P &b){
            return a.second < b.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<P,vector<P>, lamda> pq;
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }

        for(auto i:mp){
            pq.push({i.first,i.second});
        }

        string result = "";
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            string temp = string(a.second, a.first);
            result += temp;
        }
        return result;
    }
};