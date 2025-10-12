#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            res = res*10 + x%10;
            x /= 10;
        }

        if (res < INT_MIN || res > INT_MAX) return 0;
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int x = -3210;
    int res = sol.reverse(x);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho số a, hãy trả về số đảo ngược của nó
    - Nếu có số 0 ở đầu thì bỏ nó đi, còn nếu âm thì số vẫn âm
    -> quá dễ, mỗi tội không hiểu sao tính toán từ số int ra được số long long
*/