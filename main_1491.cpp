#include "vector"

using namespace std;

double average(vector<int> &salary) {
    double sum = 0;
    int maxV = salary[0];
    int minV = salary[0];
    for (const auto &s: salary) {
        sum += s;
        maxV = max(maxV, s);
        minV = min(minV, s);
    }
    return (sum - maxV - minV) / (salary.size() - 2);
}