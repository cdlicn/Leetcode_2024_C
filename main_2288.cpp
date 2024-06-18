#include "bits/stdc++.h"

using namespace std;


string discountPrices(string sentence, int discount) {
    istringstream str(sentence);
    string out;
    string res = "";
    double d = 1 - discount / 100.0;
    while (str >> out) {
        if (!res.empty()) {
            res += " ";
        }
        if (out.size() > 1 && out[0] == '$' && all_of(out.begin() + 1, out.end(), ::isdigit)) {
            stringstream s;
            s << fixed << setprecision(2) << '$' << stoll(out.substr(1)) * d;
            res += s.str();
        } else {
            res += out;
        }
    }
    return res;
}