#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxDifference(string s) {
        // map<char, int> mp;
        // for (int i = 0; i < s.length(); i++) {
        //     mp[s[i]]++;
        // }

        // int mxOF = -1, mnOF = 105;
        // int mxEF = -1, mnEF = 105;
        // for (auto x : mp) {
        //     if (x.second%2 != 0) {
        //         mxOF = x.second > mxOF ? x.second : mxOF;
        //         mnOF = x.second < mnOF ? x.second : mnOF;
        //     } else {
        //         mxEF = x.second > mxEF ? x.second : mxEF;
        //         mnEF = x.second < mnEF ? x.second : mnEF;
        //     }

        // }

        // return max(abs(mxOF - mnEF), abs(mxEF - mnOF));
        
        // Cách trên không hoạt động

        map<int, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]-'a']++;
        }

        int odd = 0;
        int even = s.length();
        for (auto x : mp) {
            if (x.second%2 == 1) {
                odd = max(odd, x.second);
            } else if (x.second != 0) {
                even = min(even, x.second);
            }
        }

        return odd - even;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "aaaaabbc";
    int res = sol.maxDifference(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/