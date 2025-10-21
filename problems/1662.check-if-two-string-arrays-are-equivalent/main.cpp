#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    string mergeStr(vector<string> vStr) {
        string res = "";
        for (int i = 0; i < vStr.size(); i++) {
            res += vStr[i];
        }

        return res;
    }
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return mergeStr(word1) == mergeStr(word2);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<string> word1 = {"a", "bcde", "fg"};
    vector<string> word2 = {"abc", "def", "g"};
    bool res = sol.arrayStringsAreEqual(word1, word2);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - 2 con tro di moi nguoi, toi luoi qua
*/