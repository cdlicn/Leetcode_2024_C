#include "vector"
#include "cmath"
#include "execution"

using namespace std;

vector<int> decrypt(vector<int> &code, int k) {
    int n = code.size();
    vector<int> res(n);
    int r = k > 0 ? k + 1 : n;
    k = abs(k);
    int s = reduce(code.begin() + r - k, code.begin() + r); // ans[0]
    for (int i = 0; i < n; i++) {
        res[i] = s;
        s += code[r % n] - code[(r - k) % n];
        r++;
    }
    return res;
}