#include "vector"
#include "unordered_map"

using namespace std;

int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> map;
    for (const auto &task: tasks) {
        map[task]++;
    }
    int res = 0;
    for (const auto [_, v]: map) {
        if (v == 1) {
            return -1;
        } else if (v % 3 == 0) {
            res += v / 3;
        } else {
            res += v / 3 + 1;
        }
    }
    return res;
}