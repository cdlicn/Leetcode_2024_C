#include "unordered_map"
#include "string"
#include "vector"

using namespace std;

int maximumLength(string s) {
    unordered_map<int, vector<int>> m;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        cnt++;
        if (i + 1 == s.size() || s[i] != s[i + 1]) {
            m[s[i]].push_back(cnt);
            cnt = 0;
        }
    }
    int res = -1;
    for (auto [k, v]: m) {
        v.push_back(0);
        v.push_back(0);
        sort(v.begin(), v.end(), greater());
        res = max({res, min(v[0] - 1, v[1]), v[0] - 2, v[2]});
    }
    return res == 0 ? -1 : res;
}