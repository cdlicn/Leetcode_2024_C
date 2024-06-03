#include "vector"

using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
    vector<int> res(num_people, 0);
    int i = 0;
    int n = 1;
    while (candies > 0) {
        res[i % num_people] += min(n, candies);
        candies -= n;
        n++;
        i++;
    }
    return res;
}