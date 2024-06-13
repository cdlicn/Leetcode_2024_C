#include "bits/stdc++.h"

using namespace std;

// TODO 2813. 子序列最大优雅度
long long findMaximumElegance(vector<vector<int>> &items, int k) {
    // 把利润从大到小排序
    ranges::sort(items, [](const auto &a, const auto &b) { return a[0] > b[0]; });
    long long ans = 0, total_profit = 0;
    unordered_set<int> vis;
    stack<int> duplicate; // 重复类别的利润
    for (int i = 0; i < items.size(); i++) {
        int profit = items[i][0], category = items[i][1];
        if (i < k) {
            total_profit += profit; // 累加前 k 个项目的利润
            if (!vis.insert(category).second) { // 重复类别
                duplicate.push(profit);
            }
        } else if (!duplicate.empty() && vis.insert(category).second) { // 之前没有的类别
            total_profit += profit - duplicate.top(); // 选一个重复类别中的最小利润替换
            duplicate.pop();
        } // else：比前面的利润小，而且类别还重复了，选它只会让 total_profit 变小，vis.size() 不变，优雅度不会变大
        ans = max(ans, total_profit + (long long) vis.size() * (long long) vis.size());
    }
    return ans;
}