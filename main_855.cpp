#include "bits/stdc++.h"

using namespace std;

// TODO 855. 考场就座
struct Comp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        int d1 = p1.second - p1.first, d2 = p2.second - p2.first;
        return d1 / 2 < d2 / 2 || (d1 / 2 == d2 / 2 && p1.first > p2.first);
    }
};

int n;
set<int> seats;
priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

ExamRoom(int n) : n(n) {

}

int seat() {
    if (seats.empty()) {
        seats.insert(0);
        return 0;
    }
    int left = *seats.begin(), right = n - 1 - *seats.rbegin();
    while (seats.size() >= 2) {
        auto p = pq.top();
        if (seats.count(p.first) > 0 && seats.count(p.second) > 0 &&
            *next(seats.find(p.first)) == p.second) { // 不属于延迟删除的区间
            int d = p.second - p.first;
            if (d / 2 < right || d / 2 <= left) { // 最左或最右的座位更优
                break;
            }
            pq.pop();
            pq.push({p.first, p.first + d / 2});
            pq.push({p.first + d / 2, p.second});
            seats.insert(p.first + d / 2);
            return p.first + d / 2;
        }
        pq.pop(); // leave 函数中延迟删除的区间在此时删除
    }
    if (right > left) { // 最右的位置更优
        pq.push({*seats.rbegin(), n - 1});
        seats.insert(n - 1);
        return n - 1;
    } else {
        pq.push({0, *seats.begin()});
        seats.insert(0);
        return 0;
    }
}

void leave(int p) {
    if (p != *seats.begin() && p != *seats.rbegin()) {
        auto it = seats.find(p);
        pq.push({*prev(it), *next(it)});
    }
    seats.erase(p);
}