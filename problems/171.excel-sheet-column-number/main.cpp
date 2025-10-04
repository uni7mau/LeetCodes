#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            res = res*26 + (columnTitle[i] - 'A' + 1);
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string columnTitle = "ZY";
    int res = sol.titleToNumber(columnTitle);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    A = 1
    B = 2
    ...
    AA = 26*1 + 1
    AB = 26*1 + 2
    ...
    BA = 26*2 + 1
    BB = 26*2 + 2
    ...

*/