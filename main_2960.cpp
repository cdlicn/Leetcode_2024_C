#include "vector"

using namespace std;

int countTestedDevices(vector<int> &batteryPercentages) {
    int res = 0;
    for (const auto &batteryPercentage: batteryPercentages) {
        if (batteryPercentage - res > 0) {
            res++;
        }
    }
    return res;
}