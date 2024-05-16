#include "vector"

using namespace std;

long long numberOfWeeks(vector<int> &milestones) {
    long long s = 0;
    int m = 0;
    for (const auto &milestone: milestones) {
        s += milestone;
        m = max(m, milestone);
    }
    return m > (s - m) + 1 ? (s - m) * 2 + 1 : s;
}
