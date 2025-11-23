#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                res.push_back("FizzBuzz");
            } else if (i % 5 == 0) {
                res.push_back("Buzz");
            } else if (i % 3 == 0) {
                res.push_back("Fizz");
            } else {
                string curr = "";
                curr += '0' + i;
                res.push_back(curr);
            }
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 3;
    vector<string> res = sol.fizzBuzz(n);
    for (auto x : res) {
        cout << x << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/