#include "vector"
#include "unordered_map"

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    unordered_map<int, int> lose;
    for (const auto &matche: matches) {
        lose[matche[1]]++;
        lose[matche[0]] += 0;
    }
    vector<vector<int>> r(2);
    for (const auto &[k, v]: lose) {
        if (v == 0) {
            r[0].emplace_back(k);
        } else if (v == 1) {
            r[1].emplace_back(k);
        }
    }
    sort(r[0].begin(), r[0].end());
    sort(r[1].begin(), r[1].end());
    return r;
}