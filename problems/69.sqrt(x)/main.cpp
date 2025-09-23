#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x;
        while (start <= end) {
            int mid = (start+end)/2;
            if (mid*mid < x) start = mid+1;
            else if (mid*mid > x) end = mid-1;
            else return mid;
        }
        
        return end;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int x = 8;
    int res = sol.mySqrt(x);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho số x không âm, trả về căn của nó, làm tròn xuống floor
        + Số trả về cũng không được âm
    - Các ràng buộc cần lưu ý:
        + Không dùng hàm có sẵn
        + Số x từ 1 đến 2^31 - 1 -> vẫn dùng int được, nhưng cộng vào thì sai
    -> 
        - Ta đã biết căn của 1 số là mũ 1/2 của số đó ví dụ như căn 8 = 3 -> 8^1/2 = 3
        - Mà mũ thì là số lượng số đó nhân với nhau VD 2^3 = 8 -> 2*2*2 = 8
        - Mũ phân số tức là mũ chuyển qua bên kia, tức là bài toán cần tìm a thỏa mãn a^2 = x
        - Dò số dạng binary là nhanh nhất
        => O(logn)
*/