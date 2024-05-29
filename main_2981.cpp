#include "vector"
#include "unordered_map"
#include "string"

using namespace std;

int maximumLength(string s) {
    unordered_map<char, vector<int>> m;
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        n++;
        if (i + 1 == s.size() || s[i + 1] != s[i]) {
            m[s[i]].push_back(n);
            n = 0;
        }
    }
    int res = 0;
    for (auto [k, v]: m) {
        v.push_back(0);
        v.push_back(0);
        sort(v.begin(), v.end(), greater());
        res = max({res, v[0] - 2, min(v[0] - 1, v[1]), v[2]});
    }
    return res == 0 ? -1 : res;
}