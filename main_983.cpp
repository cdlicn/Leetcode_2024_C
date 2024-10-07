#include"bits/stdc++.h"

using namespace std;

// TODO 983. 最低票价
int mincostTickets(vector<int> &days, vector<int> &costs) {
    int last_day = days.back();
    unordered_set<int> day_set(days.begin(), days.end());
    vector<int> memo(last_day + 1);
    auto dfs = [&](auto &&dfs, int i) -> int {
        if (i <= 0) {
            return 0;
        }
        int &res = memo[i]; // 注意这里是引用
        if (res) { // 之前计算过
            return res;
        }
        if (!day_set.count(i)) {
            return res = dfs(dfs, i - 1);
        }
        return res = min({dfs(dfs, i - 1) + costs[0],
                          dfs(dfs, i - 7) + costs[1],
                          dfs(dfs, i - 30) + costs[2]});
    };
    return dfs(dfs, last_day);
}
