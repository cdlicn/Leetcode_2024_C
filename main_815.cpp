#include "bits/stdc++.h"

using namespace std;

int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < routes.size(); i++) {
        for (int x: routes[i]) {
            mp[x].push_back(i);
        }
    }
    if (!mp.contains(source) || !mp.contains(target)) {
        return source != target ? -1 : 0;
    }
    unordered_map<int, int> dis;
    dis[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int dis_x = dis[x];
        for (int i: mp[x]) {
            for (int y: routes[i]) {
                if (!dis.contains(y)) {
                    dis[y] = dis_x + 1;
                    q.push(y);
                }
            }
            routes[i].clear();
        }
    }

    return dis.contains(target) ? dis[target] : -1;
}