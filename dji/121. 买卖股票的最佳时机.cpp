#include "bits/stdc++.h"

using namespace std;

int maxProfit(vector<int> &prices) {
    int p = 0;
    int m = prices[0];
    for (auto &price: prices) {
        if (price < m) {
            m = price;
        } else {
            p = max(price - m, p);
        }
    }
    return p;
}