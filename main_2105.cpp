#include "vector"

using namespace std;

int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int a = capacityA;
    int b = capacityB;
    int lef = 0;
    int rig = plants.size() - 1;
    int res = 0;
    while (lef < rig) {
        if (plants[lef] > a) {
            res++;
            a = capacityA;
        }
        if (plants[rig] > b) {
            res++;
            b = capacityB;
        }
        a -= plants[lef++];
        b -= plants[rig--];
    }
    if (lef == rig) {
        res += max(a, b) >= plants[lef] ? 0 : 1;
    }
    return res;
}