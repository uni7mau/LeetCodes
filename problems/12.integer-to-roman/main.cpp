#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> val = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };
        string res;
        for (pair<int, string> p : val) {
            while (num >= p.first) {
                res += p.second;
                num -= p.first;
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
    string res = sol.intToRoman(1994);
    cout << res << "\n";
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/