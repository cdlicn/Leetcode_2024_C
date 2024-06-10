#include "vector"
#include "algorithm"

using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int lef = 0;
    int rig = people.size() - 1;
    int res = 0;
    while (lef <= rig) {
        if (people[lef] + people[rig] <= limit) {
            lef++;
            rig--;
        } else {
            rig--;
        }
        res++;
    }
    return res;
}