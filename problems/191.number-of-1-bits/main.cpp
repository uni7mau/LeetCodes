#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n != 0) {
            if (n%2 == 1) {
                n--;
                res++;
            }
            n /= 2;
        }        

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 4;
    int res = sol.hammingWeight(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Đếm số bit 1 sau khi tính từ số đề cho
*/