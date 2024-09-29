#include "bits/stdc++.h"

using namespace std;
//
char kthCharacter(int k) {
    string ss = "a";
    while (ss.size() < k) {
        string tmp = "";
        for (const auto &c: ss) {
            tmp += (char) ((c - 'a' + 1) % 26 + 'a');
        }
        ss = ss + tmp;
    }
    return ss[k - 1];
}