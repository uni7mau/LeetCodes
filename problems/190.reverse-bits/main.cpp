#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int reverseBits(int n) {
        string bits = "";
        while (n != 0) {
            if (n%2 == 0) {
                bits += '0';
            } else {
                bits += '1';
                n--;
            }
            n /= 2;
        }
        for (int i = bits.length(); i < 32; i++) {
            bits += '0';
        }

        int res = 0;
        for (int i = 0; i < bits.length(); i++) {
            res += (bits[i]-'0')*pow(2, bits.length()-1-i);
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 43261596;
    int res = sol.reverseBits(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho số a
        + Chuyển số a sang bit
        + Đảo ngược bit
        + In ra giá trị của số đã đảo ngược đó
    - Các ràng buộc cần lưu ý:
        + Số khá lớn

    -> Như giải tay 
    -> Dịch bit (chịu)
*/