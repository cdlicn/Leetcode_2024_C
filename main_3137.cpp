#include "bits/stdc++.h"

using namespace std;

int minimumOperationsToMakeKPeriodic(string word, int k) {
    unordered_map<string, int> m;
    int mx = 0;
    for (int i = 0; i < word.size(); i += k) {
        mx = max(++m[word.substr(i, k)], mx);
    }
    return word.size() / k - mx;
}