#include "bits/stdc++.h"

using namespace std;

string getSmallestString(string s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] % 2 == s[i + 1] % 2 && s[i] > s[i + 1]) {
            cout << i << endl;
            char tmp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tmp;
            break;
        }
    }
    return s;
}