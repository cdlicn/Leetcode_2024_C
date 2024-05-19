#include "vector"

using namespace std;

int getWinner(vector<int> &arr, int k) {
    int mx = arr[0];
    int c = 0;
    for (int i = 1; i < arr.size() && c < k; i++) {
        if (mx < arr[i]) {
            mx = arr[i];
            c = -1;
        }
        c++;
    }
    return mx;
}
