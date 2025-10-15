#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    string bloom(string s, int i, int j) {
        while (i >= 0 && j <= s.length()-1 && s[i] == s[j]) {
            i--; j++;
        }
        
        return s.substr(i+1, j-i-1);
    }
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;

        string res = s.substr(0, 1);
        for (int i = 0; i < s.length()-1; i++) {
            string strOdd = bloom(s, i, i);
            string strEven = bloom(s, i, i+1);
            if (strOdd.length() > res.length()) res = strOdd;
            if (strEven.length() > res.length()) res = strEven;
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "babad";
    string res = sol.longestPalindrome(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    -> Bloom Algorithm
    - Không có thuật toán này đâu tôi bịa ra đấy
*/