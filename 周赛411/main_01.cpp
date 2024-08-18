#include "bits/stdc++.h"

using namespace std;

int countKConstraintSubstrings(string s, int k) {
    int cnt = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    int left = 0;
    for (int right = 0; right < s.size(); ++right) {
        if (s[right] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
        while (cnt0 > k && cnt1 > k) {
            if (s[left] == '0') {
                cnt0--;
            } else {
                cnt1--;
            }
            left++;
        }
        cnt += right - left + 1;
    }

    return cnt;
}
