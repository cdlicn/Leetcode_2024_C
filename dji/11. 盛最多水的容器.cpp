#include "bits/stdc++.h"

using namespace std;

int maxArea(vector<int> &height) {
    int lef = 0;
    int rig = height.size() - 1;
    int res = 0;
    while (lef < rig) {
        res = max(res, min(height[lef], height[rig]) * (rig - lef));
        if (height[lef] > height[rig]) {
            rig--;
        } else {
            lef++;
        }
    }
    return res;
}