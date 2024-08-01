#include "bits/stdc++.h"

using namespace std;

int maxmiumScore(vector<int> &cards, int cnt) {
    sort(cards.begin(), cards.end(), [](auto &a, auto &b) {
        return a > b;
    });
    int s = reduce(cards.begin(), cards.begin() + cnt);
    if (s % 2 == 0) {
        return s;
    }
    auto f = [&](int a) -> int {
        for (int i = cnt; i < cards.size(); i++) {
            if (cards[i] % 2 != a % 2) {
                return s - a + cards[i];
            }
        }
        return 0;
    };

    int res = f(cards[cnt - 1]);
    for (int i = cnt - 2; i >= 0; i--) {
        if (cards[i] % 2 != cards[cnt - 1] % 2) {
            res = max(res, f(cards[i]));
            break;
        }
    }
    return res;
}