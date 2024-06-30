#include "bits/stdc++.h"

using namespace std;

int maxHeightOfTriangle(int red, int blue) {
    int totalBalls = red + blue;
    int maxHeight = 0;
    for (int h = 0; h * (h + 1) / 2 <= totalBalls; h++) {
        int n1 = ceil(h / 2.0);
        int n2 = h / 2;
        int a = n1 * n1;
        int b = n2 * (n2 + 1);
        if ((a <= red && b <= blue) || (a <= blue && b <= red)) {
            maxHeight = h;
        } else {
            break;
        }
    }
    return maxHeight;
}


