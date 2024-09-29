#include "bits/stdc++.h"

using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int countOfSubstrings(string word, int k) {
    unordered_map<char, int> cnt;
    int ks = 0;
    int lef = 0, rig = 0;
    int n = word.size();
    int cs = 0;
    int res = 0;
    for (char v: "aeiou") {
        cnt[v] = 0;
    }
    while (rig < n) {
        if (!isVowel(word[rig])) {
            ks++;
        } else {
            if (cnt[word[rig]] == 0) {
                cs++;
            }
            cnt[word[rig]]++;
        }
        while (ks >= k && cs == 5) {
            if (ks == k) {
                res++;
                unordered_map<char, int> tmpCnt;
                int idx = lef;
                while (isVowel(word[idx]) && cnt[word[idx]] - tmpCnt[word[idx]] - 1 > 0) {
                    cout << idx << endl;
                    res++;
                    idx++;
                    tmpCnt[word[idx]]++;
                }
                break;
            }
            if (!isVowel(word[lef])) {
                ks--;
            } else {
                cnt[word[lef]]--;
                if (cnt[word[lef]] == 0) {
                    cs--;
                }
            }
            lef++;
        }
        rig++;
    }
    return res;
}
/*
 "aeioqq"
1
"aeiou"
0
"ieaouqqieaouqq"
1
"iqeaouqi"
2
"auaroiuerg"
 3
 */