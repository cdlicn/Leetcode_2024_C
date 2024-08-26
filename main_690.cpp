#include "bits/stdc++.h"

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

unordered_map<int, Employee *> m;

int dfs(int id) {
    int res = m[id]->importance;
    for (const auto &item: m[id]->subordinates) {
        res += dfs(item);
    }
    return res;
}

int getImportance(vector<Employee *> employees, int id) {
    for (const auto &e: employees) {
        m[e->id] = e;
    }
    return dfs(id);
}