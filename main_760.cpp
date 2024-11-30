#include "bits/stdc++.h"

using namespace std;

vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2) {
    map<int, int> mp;
    for (int i = 0; i < nums2.size(); ++i) {
        mp[nums2[i]] = i;
    }
    vector<int> res;
    for (const auto &item: nums1) {
        res.emplace_back(mp[item]);
    }
    return res;
}