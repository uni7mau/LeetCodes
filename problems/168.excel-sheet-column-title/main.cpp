#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> letter(27);
        letter[0] = 'Z';
        int i = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            letter[i++] = ch;
        }

        columnNumber--;
        string s;
        while (columnNumber >= 0){
            s.push_back(letter[columnNumber%26]);
            columnNumber /= 26;
            columnNumber--;
        }
        reverse(s.begin(), s.end());

        return s;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int columnNumber = 1;
    string res = sol.convertToTitle(columnNumber);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    Bài này chả có gì
*/