#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int res = garbage[0].length();
    bool visit[3] = {false, false, false};
    for (int i = garbage.size() - 1; i > 0; i--) {
        res += garbage[i].length();
        if (garbage[i].find("M") != -1) {
            visit[0] = true;
        }
        if (garbage[i].find('P') != -1) {
            visit[1] = true;
        }
        if (garbage[i].find('G') != -1) {
            visit[2] = true;
        }
        if (visit[0]) {
            res += travel[i - 1];
        }
        if (visit[1]) {
            res += travel[i - 1];
        }
        if (visit[2]) {
            res += travel[i - 1];
        }
    }
    return res;
}