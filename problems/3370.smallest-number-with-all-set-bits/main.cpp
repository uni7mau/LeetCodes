#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        while (n > 0) {
            n /= 2;
            cnt++;
        }

        int res = 0;
        for (int i = 0; i < cnt; i++) {
            res += pow(2, i);
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
    int res = sol.smallestNumber(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Số lớn gần nhất mà toàn là bit1 chính là độ dài sau khi chia thập phân thành chuỗi nhị phân
*/