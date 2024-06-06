#include "string"

using namespace std;

long long minimumSteps(string s) {
    long long res = 0;
    int idx0 = s.size() - 1;
    int idx1 = 0;
    while (idx0 >= 0 && s[idx0] != '0') {
        idx0--;
    }
    while (idx1 < s.size() && s[idx1] != '1') {
        idx1++;
    }
    while (idx0 > idx1) {
        res += idx0 - idx1;
        idx0--;
        idx1++;
        while (idx0 >= 0 && s[idx0] != '0') {
            idx0--;
        }
        while (idx1 < s.size() && s[idx1] != '1') {
            idx1++;
        }
    }
    return res;
}