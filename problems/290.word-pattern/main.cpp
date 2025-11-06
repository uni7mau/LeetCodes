#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        
        while (ss >> word) words.push_back(word);

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> ump;
        unordered_set<string> us;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (ump.count(c)) {
                if (ump[c] != w) return false;
            } else {
                if (us.count(w)) return false;
                ump[c] = w;
                us.insert(w); }
        }

        return true;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string pattern = "abba", s = "dog cat cat dog";
    bool res = sol.wordPattern(pattern, s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - 
*/