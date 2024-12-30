#include "bits/stdc++.h"

using namespace std;

vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    int i = 0, j = 0, k = 0;
    int n = arr1.size(), m = arr2.size(), s = arr3.size();
    vector<int> res;
    while (i < n && j < m && k < s) {
        int a1 = arr1[i], a2 = arr2[j], a3 = arr3[k];
        if (a1 == a2 && a2 == a3) {
            i++, j++, k++;
            res.emplace_back(a1);
        } else if (a1 <= a2 && a1 <= a3) {
            i++;
        } else if (a2 <= a1 && a2 <= a3) {
            j++;
        } else if (a3 <= a2 && a3 <= a1) {
            k++;
        }
    }
    return res;
}