#include "vector"

using namespace std;

int maxOperations(vector<int> &nums) {
    int res = 1;
    for (int i = 2; i < nums.size(); i += 2) {
        if (i + 1 < nums.size() && nums[i] + nums[i + 1] == nums[i - 2] + nums[i - 1]) {
            res++;
        } else {
            break;
        }
    }
    return res;
}