#include "bits/stdc++.h"

using namespace std;

string stringHash(string s, int k) {
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i += k) {
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += s[i + j] - 'a';
        }
        sum %= 26;
        res = res + (char) (sum + 'a');
    }
    return res;
}