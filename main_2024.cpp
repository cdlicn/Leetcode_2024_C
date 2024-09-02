#include "bits/stdc++.h"

using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int n = 0, res = 0;
    for (int lef = 0, rig = 0; rig < answerKey.size(); rig++) {
        if (answerKey[rig] == 'T') {
            n++;
        }
        if (rig - lef + 1 - n > k && n > k) {
            if (answerKey[lef] == 'T') {
                n--;
            }
            lef++;
        }
        res = max(res, rig - lef + 1);
    }
    return res;
}