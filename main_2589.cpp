#include "numeric"
#include "vector"
#include "algorithm"

using namespace std;

int findMinimumTime(vector<vector<int>> &tasks) {
    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
    int ans = 0;
    vector<int> run(tasks.back()[1] + 1);
    for (auto &t: tasks) {
        int start = t[0], end = t[1], d = t[2];
        d -= reduce(run.begin() + start, run.begin() + end + 1); // 去掉运行中的时间点
        for (int i = end; d > 0; i--) { // 剩余的 d 填充区间后缀
            if (!run[i]) {
                run[i] = true; // 运行
                d--;
                ans++;
            }
        }
    }
    return ans;
}