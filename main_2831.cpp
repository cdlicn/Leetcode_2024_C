#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

int longestEqualSubarray(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]].push_back(i - map[nums[i]].size());
    }
    int res = 0;
    for (const auto &[key, idx]: map) {
        int left = 0;
        for (int right = 0; right < idx.size(); right++) {
            while (idx[right] - idx[left] > k) {
                left++;
            }
            res = max(res, right - left + 1);
        }
    }
    return res;
}