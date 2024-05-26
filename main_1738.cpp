#include "vector"
#include "queue"

using namespace std;

int kthLargestValue(vector<vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> xs(m + 1, vector<int>(n + 1, 0));
    priority_queue<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            xs[i + 1][j + 1] = xs[i + 1][j] ^ xs[i][j + 1] ^ xs[i][j] ^ matrix[i][j];
            q.emplace(xs[i + 1][j + 1]);
        }
    }
    while (k > 1) {
        q.pop();
        k--;
    }
    return q.top();
}