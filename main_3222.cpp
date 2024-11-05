#include "bits/stdc++.h"

using namespace std;


string losingPlayer(int x, int y) {
    int n = 0;
    while (x > 0 && y >= 4) {
        x -= 1;
        y -= 4;
        n++;
    }
    return n % 2 == 1 ? "Alice" : "Bob";
}