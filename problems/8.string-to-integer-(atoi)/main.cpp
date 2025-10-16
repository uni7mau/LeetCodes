#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int myAtoi(string s) {
        bool nega = false;

        long long res = 0;
        int i = 0;
        while (i < s.length() && s[i] == ' ') i++;
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            nega = s[i] == '-';
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            res = res*10 + (s[i] - '0');
            
            if (nega == true && -res < INT_MIN) return INT_MIN;
            if (nega == false && res > INT_MAX) return INT_MAX;
            i++;
        }

        return nega ? -res : res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "-91283472332";
    int res = sol.myAtoi(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho chuỗi ký tự, hãy chuyển chuỗi số này về dạng int32
    - Được thực hiện theo các bước sau đây: 
        + B1: Kiểm tra xem có khoảng trống ở đầu không, có thì bỏ hết
        + B2: kiểm tra xem ký tự tiếp theo có là + hay - không, + thì thôi còn - thì res = âm
        + B3: kiểm tra lần lượt đến cuối ký tự tiếp theo có là space không, có thì bỏ qua chỉ lấy chữ số
        + B4: nếu số mà quá int 32bit thì làm tròn về cận
        + B5: trả về kết quả là số int32 bit

    -> Giải như cách làm đề cho, nhưng khi submit nhớ đổi thành long long, lý do là tham số s truyền vào có thể nhiều hơn int,
    khi ta nhân 10 để tính giá trị tiếp theo thì sẽ báo lỗi trước khi mình kiểm tra < và > INT_MIN, INT_MAX
*/