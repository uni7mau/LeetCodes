#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        vector<string> v(numRows, "");
        int j = 0, change = -1;
        for (int i = 0; i < s.length(); i++) {
            if (j == 0 || j == numRows-1) change *= -1;
            v[j].push_back(s[i]);
            if (change == 1) j++;
            else j--;
        }
        string res = "";
        for (string x:v) res += x;

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string res = sol.convert(s, numRows);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    ?
*/