#include "vector"

using namespace std;

int maximumEnergy(vector<int> &energy, int k) {
    int res = INT_MIN;
    int n = energy.size();
    for (int i = n - 1; i > n - k - 1; i--) {
        int idx = i;
        int s = 0;
        while (idx >= 0) {
            s += energy[idx];
            res = max(s, res);
            idx -= k;
        }
    }
    return res;
}