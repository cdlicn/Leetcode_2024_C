#include "bits/stdc++.h"

using namespace std;

int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
    int sum = 0;
    int n = distance.size();
    int res = 0;
    for (const auto &item: distance) {
        sum += item;
    }
    while (start != destination) {
        res += distance[start];
        start = (start + 1) % n;
    }
    return min(res, sum - res);
}