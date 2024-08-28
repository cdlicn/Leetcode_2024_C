#include "bits/stdc++.h"

using namespace std;

// TODO 3144. 分割字符频率相等的最少子字符串
int minimumSubstringsInPartition(string s) {
    int n = s.size();
    vector<int> memo(n);
    auto dfs = [&](auto &&dfs, int i) {
        if (i < 0) {
            return 0;
        }
        int &res = memo[i];
        if (res) {
            return res;
        }
        res = INT_MAX;
        int cnt[26]{}, k = 0, max_cnt = 0;
        for (int j = i; j >= 0; j--) {
            k += cnt[s[j] - 'a']++ == 0;
            max_cnt = max(max_cnt, cnt[s[j] - 'a']);
            if (i - j + 1 == k * max_cnt) {
                res = min(res, dfs(dfs, j - 1) + 1);
            }
        }
        return res;
    };
    return dfs(dfs, n - 1);
}