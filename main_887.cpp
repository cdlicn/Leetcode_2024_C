#include "bits/stdc++.h"

using namespace std;

// TODO 887. 鸡蛋掉落
vector<vector<int>> memo{{}};

int dfs(int i, int j) {
    if (i == 0 || j == 0) {
        return 0;
    }
    int &res = memo[i][j]; // 注意这里是引用
    if (res != 0) { // 之前计算过
        return res;
    }
    return res = dfs(i - 1, j) + dfs(i - 1, j - 1) + 1;
};

int superEggDrop(int k, int n) {
    for (int i = 1;; i++) {
        memo.emplace_back(k + 1); // 插入一个长为 k+1 的 vector
        if (dfs(i, k) >= n) {
            return i;
        }
    }
}