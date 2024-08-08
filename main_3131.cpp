#include "bits/stdc++.h"

using namespace std;

int addedInteger(vector<int> &nums1, vector<int> &nums2) {
    int mx1 = nums1[0];
    int mx2 = nums2[0];
    for (int i = 1; i < nums1.size(); i++) {
        mx1 = max(mx1, nums1[i]);
        mx2 = max(mx2, nums2[i]);
    }
    return mx2 - mx1;
}