#include "string"
#include "cmath"

using namespace std;

int findPermutationDifference(string s, string t) {
    int res = 0;
    int n = s.size();
    int p[26];
    for (int i = 0; i < n; i++) {
        p[s[i] - 'a'] = i;
    }
    for (int i = 0; i < n; i++) {
        res += abs(p[t[i] - 'a'] - i);
    }
    return res;
}