#include <algorithm>
#include "vector"
#include "unordered_map"

using namespace std;

vector<vector<int>> memo;

int dfs(vector<int> &nums, int i, int j, int target) {
    if (i >= j) {
        return 0;
    }
    int &res = memo[i][j];
    if (res != -1) {
        return res;
    }
    res = 0;
    if (nums[i] + nums[i + 1] == target) {
        res = max(res, dfs(nums, i + 2, j, target) + 1);
    }
    if (nums[j - 1] + nums[j] == target) {
        res = max(res, dfs(nums, i, j - 2, target) + 1);
    }
    if (nums[i] + nums[j] == target) {
        res = max(res, dfs(nums, i + 1, j - 1, target) + 1);
    }
    return res;
}

int maxOperations(vector<int> &nums) {
    int n = nums.size();
    memo.resize(n, vector<int>(n));
    for (auto &row: memo) {
        fill(row.begin(), row.end(), -1);
    }
    int res1 = dfs(nums, 2, n - 1, nums[0] + nums[1]);
    for (auto &row: memo) {
        fill(row.begin(), row.end(), -1);
    }
    int res2 = dfs(nums, 0, n - 3, nums[n - 2] + nums[n - 1]);
    for (auto &row: memo) {
        fill(row.begin(), row.end(), -1);
    }
    int res3 = dfs(nums, 1, n - 2, nums[0] + nums[n - 1]);
    return max({res1, res2, res3}) + 1;
}