#include "bits/stdc++.h"

using namespace std;

string getSmallestString(string s, int k) {
    for (char &c: s) {
        int dis = min(c - 'a', 'z' - c + 1);
        if (dis > k) {
            c -= k;
            break;
        }
        c = 'a';
        k -= dis;
    }
    return s;
}