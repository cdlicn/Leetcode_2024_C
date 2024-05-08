#include "vector"

using namespace std;

int wateringPlants(vector<int> &plants, int capacity) {
    int n = plants.size();
    int res = n;
    int nowC = capacity;
    for (int i = 0; i < n; i++) {
        if (nowC < plants[i]) {
            nowC = capacity;
            res += 2 * i;
        }
        nowC -= plants[i];
    }
    return res;
}