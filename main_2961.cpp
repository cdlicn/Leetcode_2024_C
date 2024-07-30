#include "bits/stdc++.h"

using namespace std;

int pow(int x, int n, int mod) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
    vector<int> res;
    for (int i = 0; i < variables.size(); ++i) {
        int a = variables[i][0] % 10, b = variables[i][1], c = variables[i][2], m = variables[i][3];
        if (pow(pow(a, b, 10), c, m) % m == target) {
            res.emplace_back(i);
        }
    }
    return res;
}