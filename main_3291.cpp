#include "bits/stdc++.h"

using namespace std;

// TODO 3291. 形成目标字符串需要的最少字符串数 I
vector<int> calc_z(string s) {
    int n = s.length();
    vector<int> z(n);
    int box_l = 0, box_r = 0; // z-box 左右边界（闭区间）
    for (int i = 1; i < n; i++) {
        if (i <= box_r) {
            z[i] = min(z[i - box_l], box_r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            box_l = i;
            box_r = i + z[i];
            z[i]++;
        }
    }
    return z;
}

// 桥的概念，见我在 45 或 1326 题下的题解
int jump(vector<int> &max_jumps) {
    int ans = 0;
    int cur_r = 0; // 已建造的桥的右端点
    int nxt_r = 0; // 下一座桥的右端点的最大值
    for (int i = 0; i < max_jumps.size(); i++) {
        nxt_r = max(nxt_r, i + max_jumps[i]);
        if (i == cur_r) { // 到达已建造的桥的右端点
            if (i == nxt_r) { // 无论怎么造桥，都无法从 i 到 i+1
                return -1;
            }
            cur_r = nxt_r; // 造一座桥
            ans++;
        }
    }
    return ans;
}

int minValidStrings(vector<string> &words, string &target) {
    int n = target.length();
    vector<int> max_jumps(n);
    for (auto &word: words) {
        vector<int> z = calc_z(word + "#" + target);
        int m = word.length() + 1;
        for (int i = 0; i < n; i++) {
            max_jumps[i] = max(max_jumps[i], z[m + i]);
        }
    }
    return jump(max_jumps);
}