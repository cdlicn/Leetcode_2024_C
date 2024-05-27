#include "vector"

using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    int sum = mean * (n + rolls.size());
    for (const auto &roll: rolls) {
        sum -= roll;
    }
    if (sum < n || sum > n * 6) {
        return {};
    }
    vector<int> res(n, sum / n);
    sum -= n * (sum / n);
    int i = 0;
    while (sum != 0) {
        res[i++]++;
        sum--;
    }
    return res;
}