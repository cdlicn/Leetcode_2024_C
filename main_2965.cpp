#include "vector"
#include "unordered_map"

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
    unordered_map<int, int> m;
    int n = grid.size() * grid.size();
    for (const auto &g: grid) {
        for (const auto &i: g) {
            m[i]++;
        }
    }
    int r1, r2;
    for (int i = 1; i <= n; i++) {
        if (m[i] == 0) {
            r2 = i;
        } else if (m[i] == 2) {
            r1 = i;
        }
    }
    return {r1, r2};
}