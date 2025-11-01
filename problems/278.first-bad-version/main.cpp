#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right)/2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }

        return left;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 5, bad = 4;
    int res = sol.firstBadVersion(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Yêu cầu là tìm con bị lỗi ở đầu chuyền bị lỗi
    -> Dùng tìm nhị phân nếu gặp con lỗi ở mid thì chuyển right về mid, không thì left cứ tăng dần đến khi mà 
    gặp left = right thì đó là con bị lỗi
*/