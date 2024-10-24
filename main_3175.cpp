#include "bits/stdc++.h"

using namespace std;

int findWinningPlayer(vector<int> &skills, int k) {
    int n = 0;
    int idx = 0;
    for (int i = 1; i < skills.size() && n < k; i++) {
        if (skills[i] > skills[idx]) {
            n = 0;
            idx = i;
        }
        n++;
    }
    return idx;
}