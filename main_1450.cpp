#include "bits/stdc++.h"

using namespace std;

int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int res = 0;
    int n = startTime.size();
    for (int i = 0; i < n; ++i) {
        if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
            res++;
        }
    }
    return res;
}