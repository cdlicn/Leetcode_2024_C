#include "bits/stdc++.h"

using namespace std;

int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int i = 0;
    int c;
    for (const auto &bus: buses) {
        for (c = capacity; c && i < passengers.size() && passengers[i] <= bus; c--) {
            i++;
        }
    }
    i -= 1;
    int res = c ? buses.back() : passengers[i];
    while (i >= 0 && res == passengers[i]) {
        res--;
        i--;
    }
    return res;
}