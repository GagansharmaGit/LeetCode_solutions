class Solution {
public:

    void DFS(int starting_point,int prev,unordered_map<int,vector<int>>&adj,vector<int>&result){
        result.push_back(starting_point);
        
        for(int &v : adj[starting_point]) {
            if(v != prev) {
                DFS(v, starting_point, adj,result);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;

        for(auto i:adjacentPairs){
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        int starting_point = -1;

        for(auto i:adj){
            if(i.second.size() == 1){
                starting_point = i.first;
                break;
            }
        }

        vector<int>result;
        int prev = INT_MIN;
        DFS(starting_point,prev,adj,result);

        return result;
    }
};