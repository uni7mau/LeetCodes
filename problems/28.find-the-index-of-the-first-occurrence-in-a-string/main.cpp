#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int strStr(string haystack, string needle) {
        // Cách 1:
        // if (needle.length() > haystack.length()) return -1;

        // int res = -1, pos = 0;
        // while (pos < haystack.length()) {
        //     if (haystack[pos] == needle[0]) {
        //         res = pos;
        //         int pos2 = 0, save = pos;
        //         while (1) {
        //             if (pos2 == needle.size()) break;

        //             if (haystack[pos] == needle[pos2]) {
        //                 pos2++;
        //             } else {
        //                 res = -1;
        //                 break;
        //             }

        //             pos++;
        //         }

        //         if (pos2 == needle.size()) break;
        //         else pos = save + 1;
        //     } else {
        //         pos++;
        //     }
        // }

        // return res;

        // Cách 2:
        if (needle.length() > haystack.length()) return -1;

        for (int i = 0; i <= haystack.length()-needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) return i;
        }

        return -1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string str1 = "mississippi", str2 = "issip";
    int res = sol.strStr(str1, str2);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây  
    - Làm rõ thông tin:
        + Cho 2 chuỗi, kiểm tra chuỗi b có nằm trong chuỗi a không
        + Nếu có thì in ra vị trí trùng đầu tiên, không thì in ra -1
    - Các ràng buộc cần chú ý:
        + Độ dài chuỗi tối đa là 10^4
        + 2 chuỗi đều là lower case
    -> Cách 1 (mất não):
        - Nếu gặp ký tự đầu giống thì bắt đầu lặp 
            + Nếu độ dài currString = string2 thì break và return
            + Nếu giống thì pos2 (vị trí tại string2) tăng lên để xét tiếp, pos1 cũng tăng lên
            + Nếu khác thì kết quả là -1 và break ra, lấy pos là vị trí lúc xét ban đầu + 1
            => O(n1*n2)

    -> Cách 2 (dùng hàm substr):
        - Dùng hàm là xong, duyệt từ đầu đến string1.length()-string2.length()
        - Cắt theo độ dài string2 ra rồi so sánh với nó, bằng thì return i, không thì để nó chạy đến cuối rồi return 1
        => O(n1*n2) 
*/