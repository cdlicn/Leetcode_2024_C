#include "bits/stdc++.h"

using namespace std;

int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
    ranges::sort(nums1);
    ranges::sort(nums2);
    int j = 0;
    for (int i = 2; i >= 0; i--) {
        int x = nums2[0] - nums1[i];
        j = 0;
        for (int k = i; k < nums1.size(); k++) {
            if (nums1[k] + x == nums2[j] && ++j == nums2.size()) {
                return x;
            }
        }
    }
    return -1;
}