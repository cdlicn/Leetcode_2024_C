#include "vector"
#include "stack"

using namespace std;

vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> stk;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        while (!stk.empty() && num < stk.back() && stk.size() + nums.size() - i > k) {
            stk.pop_back();
        }
        if (stk.size() < k) {
            stk.push_back(num);
        }
    }
    return stk;
}