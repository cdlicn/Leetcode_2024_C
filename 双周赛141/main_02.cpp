#include "bits/stdc++.h"

using namespace std;

vector<int> minBitwiseArray(vector<int> &nums) {
//    int n = nums.size();
//    vector<int> ans(n, -1);
//    for (int i = 0; i < nums.size(); i++) {
//        int x = nums[i];
//        if (x != 2) {
//            string str = bitset<32>(nums[i]).to_string();
//            str[str.find_last_of('0') + 1] = '0';
//            ans[i] = bitset<32>(str).to_ulong();
//        }
//    }
//    return ans;
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        if(x == 2) {
            continue;
        }
        int s = -1;
        while ((x & 1) == 1) {
            s++;
            x >>= 1;
        }
        ans[i] = nums[i] ^ (1 << s);
    }
    return ans;
}