#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int totalMoney(int n) {
        int q = n/7, r = n%7;   
        return 28*q + 7*q*(q-1)/2 + (2*q+r+1)*r/2;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 20;
    int res = sol.totalMoney(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Họ gửi tiền n ngày, bắt đầu từ thứ 2 với 1$
    - Từ thứ 3 đến chủ nhật tiền tăng 1$ so với ngày hôm trước
    - Từ thứ 2 lần 2 đến sau này tiền tăng 1$ so với thứ 2 tuần trước
    -> Dùng mảng như bình thường hoặc dùng toán học
*/