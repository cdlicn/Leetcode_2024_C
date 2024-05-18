#include "algorithm"
#include "vector"

using namespace std;

int maxDivScore(vector<int> &nums, vector<int> &divisors) {
    int max_cnt = -1, ans = 0;
    for (int d: divisors) {
        int cnt = ranges::count_if(nums, [&](int x) {
            return x % d == 0;
        });
        if (cnt > max_cnt || cnt == max_cnt && d < ans) {
            max_cnt = cnt;
            ans = d;
        }
    }
    return ans;
}