class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>que;
        for(auto i:stones){
            que.push(i);
        }

        while(que.size() > 1){
            int a = que.top();
            que.pop();
            int b =que.top();
            que.pop();

            que.push(abs(a-b));
        }

        return que.top();
    }
};