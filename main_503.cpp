#include "bits/stdc++.h"

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 2 * n - 1; i >= 0; i--) {
        int x = nums[i % n];
        while (!stk.empty() && x >= stk.top()) {
            stk.pop();
        }
        if (i < n && !stk.empty()) {
            res[i] = stk.top();
        }
        stk.push(x);
    }
    return res;
}