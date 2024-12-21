#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    ranges::sort(score, {}, [&](auto &row) { return -row[k]; });
    return score;
}