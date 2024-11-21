#include "bits/stdc++.h"

using namespace std;

int finalPositionOfSnake(int n, vector<string> &commands) {
    int i = 0;
    int j = 0;
    for (const auto &c: commands) {
        if (c == "UP") {
            i -= 1;
        } else if (c == "RIGHT") {
            j += 1;
        } else if (c == "DOWN") {
            i += 1;
        } else {
            j -= 1;
        }
    }
    return i * n + j;
}