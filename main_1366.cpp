#include "bits/stdc++.h"

using namespace std;

string rankTeams(vector<string> &votes) {
    int m = votes[0].size();
    vector cnts(26, vector<int>(m));
    for (const auto &vote: votes) {
        for (int i = 0; i < m; ++i) {
            cnts[vote[i] - 'A'][i]--;
        }
    }
    string res = votes[0];
    // todo
    ranges::sort(res, {}, [&](char a) {
        return make_pair(cnts[a - 'A'], a);
    });
    //

    return res;
}