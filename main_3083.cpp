#include "bits/stdc++.h"

using namespace std;

bool isSubstringPresent(string s) {
    bool v[26][26]{};
    for (int i = 1; i < s.size(); ++i) {
        v[s[i - 1] - 'a'][s[i] - 'a'] = true;
        if (v[s[i] - 'a'][s[i - 1] - 'a']) {
            return true;
        }
    }
    return false;
}