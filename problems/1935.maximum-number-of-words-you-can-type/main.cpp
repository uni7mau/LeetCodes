#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenKeys;
        
        for (auto& c : brokenLetters) {
            brokenKeys.insert(c);
        }
        
        stringstream ss(text);
        string word;
        vector<string> words;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        int count = 0;
        for (auto w : words) {
            for (char c : w) {
                if (brokenKeys.find(c) != brokenKeys.end()) {
                    count++;
                    break;
                }
            }
        }

        return words.size() - count;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string text = "hello world", brokenLetters = "ad";
    int res = sol.canBeTypedWords(text, brokenLetters);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/