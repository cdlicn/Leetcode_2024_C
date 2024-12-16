#include "bits/stdc++.h"

using namespace std;

// TODO 1847. 最近的房间
vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
    // 按照 size 从大到小排序
    ranges::sort(rooms, {}, [](auto &a) { return -a[1]; });

    int q = queries.size();
    vector<int> query_ids(q);
    iota(query_ids.begin(), query_ids.end(), 0);
    // 按照 minSize 从大到小排序
    ranges::sort(query_ids, {}, [&](int i) { return -queries[i][1]; });

    vector<int> ans(q, -1);
    set<int> room_ids;
    int j = 0;
    for (int i: query_ids) {
        int preferred_id = queries[i][0], min_size = queries[i][1];
        while (j < rooms.size() && rooms[j][1] >= min_size) {
            room_ids.insert(rooms[j][0]);
            j++;
        }

        int diff = INT_MAX;
        auto it = room_ids.lower_bound(preferred_id);
        if (it != room_ids.begin()) {
            auto p = prev(it);
            diff = preferred_id - *p; // 左边的差
            ans[i] = *p;
        }
        if (it != room_ids.end() && *it - preferred_id < diff) { // 右边的差更小
            ans[i] = *it;
        }
    }
    return ans;
}