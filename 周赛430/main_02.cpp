#include "bits/stdc++.h"

using namespace std;

string answerString(string word, int numFriends) {
    if (numFriends == 1) {
        return word;
    }
    string res;
    char mx = 0;
    vector<int> vs;
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (c > mx) {
            mx = c;
            vs.clear();
            vs.emplace_back(i);
        } else if (c == mx) {
            vs.emplace_back(i);
        }
    }
    if (word.size() == numFriends) {
        res = mx;
        return res;
    }
    for (const auto &i: vs) {
        string tmp = word.substr(i, word.size() - numFriends + 1);
        if (tmp.compare(res) > 0) {
            res = tmp;
        }
    }
    return res;
}
/*
 "dbca"
2
"gggg"
4
"fb"
2
"gh"
1
"dbc"
2
"aann"
2
 */