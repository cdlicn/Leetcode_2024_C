#include "string"
#include "vector"

using namespace std;

vector<string> findWords(vector<string> &words) {
    string l = "12210111011122000010020202";
    vector<string> res;
    for (const auto &word: words) {
        bool f = true;
        for (int i = 0; i < word.size() - 1; i++) {
            if (l[tolower(word[i]) - 'a'] != l[tolower(word[i + 1]) - 'a']) {
                f = false;
            }
        }
        if (f) {
            res.push_back(word);
        }
    }
    return res;
}