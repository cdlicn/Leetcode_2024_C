//#include "bits/stdc++.h"
//
//using namespace std;
//
//static bool cmp(pair<int, int> &a, pair<int, int> &b) {
//    return a.first > b.first;
//}
//
//string boldWords(vector<string> &words, string s) {
//    if (words.size() == 0) {
//        return s;
//    }
//    vector<pair<int, int>> v;
//    for (const auto &word: words) {
//        int idx = 0;
//        while (s.find(word, idx) != string::npos) {
//            idx = s.find(word, idx);
//            v.emplace_back(idx, idx + word.size());
//            idx++;
//        }
//    }
//    sort(v.begin(), v.end(), cmp);
//    vector<int> iv;
//    iv.emplace_back(v[0].first);
//    iv.emplace_back(v[0].second);
//    for (int i = 1; i < v.size(); i++) {
//        if (v[i].first < iv.back()) {
//            iv.back() = v[i].second;
//        } else {
//            iv.emplace_back(v[i].first);
//            iv.emplace_back(v[i].second);
//        }
//    }
//    bool st = true;
//    int l = 0;
//    for (const auto &idx: iv) {
//        if (st) {
//            s.insert(idx + l, "<b>");
//            l += 3;
//        } else {
//            s.insert(idx + l, "</b>");
//            l += 4;
//        }
//        st = !st;
//    }
//    return s;
//}