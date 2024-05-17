#include "vector"
#include "algorithm"

using namespace std;

int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    int n = difficulty.size();
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = {difficulty[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end());
    sort(worker.begin(), worker.end());
    int res = 0, j = 0, max_profit = 0;
    for (int w: worker) {
        while (j < n && jobs[j].first <= w) {
            max_profit = max(max_profit, jobs[j++].second);
        }
        res += max_profit;
    }
    return res;
}