#include "vector"

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;
    int l1 = 0, l2 = 0;
    int n = nums1.size();
    int m = nums2.size();
    while (l1 < n && l2 < m) {
        while (l1 + 1 < n && nums1[l1 + 1] == nums1[l1]) {
            l1++;
        }
        while (l2 + 1 < m && nums2[l2 + 1] == nums2[l2]) {
            l2++;
        }
        if (nums1[l1] == nums2[l2]) {
            res.push_back(nums1[l1]);
            l1++;
            l2++;
        } else if (nums1[l1] < nums2[l2]) {
            l1++;
        } else {
            l2++;
        }
    }
    return res;
}