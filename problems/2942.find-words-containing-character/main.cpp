#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (auto j:words[i]) {
                if (j == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<string> words = {"leet","code"};
    char x = 'e';
    vector<int> res = sol.findWordsContaining(words, x);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/