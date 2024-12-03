#include "bits/stdc++.h"

using namespace std;

bool checkTwoChessboards(string s, string t) {
    return ((s[0] ^ s[1]) & 1) == ((t[0] ^ t[1]) & 1);
}