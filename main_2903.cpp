#include "vector"
#include "algorithm"

using namespace std;

vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference) {
    for (int i = indexDifference; i < nums.size(); i++) {
        for (int j = 0; j <= i - indexDifference; j++) {
            if (abs(nums[i] - nums[j]) >= valueDifference) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}