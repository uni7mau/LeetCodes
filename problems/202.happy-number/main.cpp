#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;
        while (floor(log10(pow(n, 2))) + 1 != 1) {
            int sum = 0;
            while (n != 0) {
                sum += pow(n%10, 2);
                n /= 10;
            }
            if (mp[sum]) break;
            mp[sum] = true;
            n = sum;
        }
        
        return n == 1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 4;
    bool res = sol.isHappy(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho số n
        + Hỏi tách liên tục rồi lấy tổng của 2 phần tử bình phương thì có về 1 được không
    - Các ràng buộc cần lưu ý:
        + Chắc chắn >= 1
    -> Giải bình thường thì tách bằng while nhưng cách này hơi lâu
    -> 
*/