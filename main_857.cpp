#include "numeric"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

double mincostToHireWorkers(vector<int> &quality, vector<int> &wage,
                            int k) {
    int n = quality.size();
    int sum = 0;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return wage[i] * quality[j] < wage[j] * quality[i];
    });
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i) {
        pq.push(quality[id[i]]);
        sum += quality[id[i]];
    }
    double res = sum * ((double) wage[id[k - 1]] / quality[id[k - 1]]);
    for (int i = k; i < n; i++) {
        int q = quality[id[i]];
        if (q < pq.top()) {
            sum -= pq.top() - q;
            pq.pop();
            pq.push(q);
            res = min(res, sum * ((double) wage[id[i]] / q));
        } else if (q == pq.top()) {
            return res;
        }
    }
    return res;
}