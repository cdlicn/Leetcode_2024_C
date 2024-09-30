#include "bits/stdc++.h"

using namespace std;

class SeatManager {
    int s = 0;
    priority_queue<int, vector<int>, greater<>> q;

public:
    SeatManager(int) {}

    int reserve() {
        if (!q.empty()) {
            int res = q.top();
            q.pop();
            return res;
        }
        return ++s;
    }

    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};