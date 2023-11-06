class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int seat_avav;
    SeatManager(int n) {
        seat_avav = 1;
    }
    
    int reserve() {
        if(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            return temp;
        }

        int temp1 = seat_avav;
        seat_avav++;
        return temp1;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */