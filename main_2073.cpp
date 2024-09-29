#include "bits/stdc++.h"

using namespace std;

int timeRequiredToBuy(vector<int> &tickets, int k) {
    int ans = 0, tk = tickets[k];
    for (int i = 0; i < tickets.size(); i++) {
        ans += min(tickets[i], tk - (i > k));
    }
    return ans;
}