#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    string addBinary(string a, string b) {
        // Cách 1: (con người giải sao máy giải như thế)
        // if (a.length() < b.length()) swap(a, b);

        // string res = a;
        // int pos = 1, lft = 0;
        // while (pos <= b.length()) {
        //     if (a[a.length()-pos] == '1' && b[b.length()-pos] == '1') {
        //         if (lft) {
        //             res[a.length()-pos] = '1';
        //         } else {
        //             res[a.length()-pos] = '0';
        //         }
        //         lft = 1;
        //     } else if (a[a.length()-pos] == '0' && b[b.length()-pos] == '0') {
        //         if (lft) {
        //             lft = 0;
        //             res[a.length()-pos] = '1';
        //         } else {
        //             res[a.length()-pos] = '0';
        //         }
        //     } else if (lft) res[a.length()-pos] = '0';
        //     else {
        //         res[a.length()-pos] = '1';
        //         lft = 0;
        //     }

        //     pos++;
        // }

        // while (pos <= a.length()) {
        //     if (!lft) {
        //         res[a.length()-pos] = a[a.length()-pos];
        //     } else {
        //         if (a[a.length()-pos] == '1') {
        //             lft = 1;
        //             res[a.length()-pos] = '0';
        //         } else {
        //             lft = 0;
        //             res[a.length()-pos] = '1';
        //         }
        //     }

        //     pos++;
        // }

        // cout << res << "\n";

        // if (lft && a[0] == '1') {
        //     string newRes; 
        //     newRes += '1';
        //     for (int i = 0; i < a.length(); i++) {
        //         newRes += res[i];
        //     }       
            
        //     return newRes;
        // } else if (lft) {
        //     res[0] = '1';
        // }

        // return res;
    
        // Cách 2:
        string res;
        int pA = a.length()-1, pB = b.length()-1;
        int carry = 0;

        while (pA >= 0 || pB >= 0 || carry) {
            if (pA >= 0) carry += a[pA--] - '0';
            if (pB >= 0) carry += b[pB--] - '0';

            res += carry%2 + '0';
            carry /= 2;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string a = "101111", b = "10";
    string res = sol.addBinary(a, b);
    cout << res;    
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin: 
        + Cho 2 chuỗi binary (0 và 1)
        + Trả về tổng của 2 chuỗi này
    - Ràng buộc cần lưu ý:
        + Độ dài cho đến 10^4
        + a và b chỉ chứa 0 hoặc 1
        + Chuỗi không chứa 0 ở đầu trừ khi tự nó là 0
    -> Cách 1: Duyệt từ cuối lên
        - Nếu là cộng 2 cái 1 thì trả về 0 và dư 1
        - Nếu là cộng 2 cái 1 và 0, 0 và 1, hoặc 0 và 0 thì cộng như số bình thường không dư nếu không dư
        - Nếu dư thì thêm 1
        - Nói chung là như người bình thường giải
        => O(max(abs(a), abs(b))) nhưng mà ngồi giải lâu
    -> Cách 2: 
        - Thay vì lưu từ cuối lên theo đúng cách giải tay, thì cứ làm xong reverse nó sẽ tiện hơn
        - Cho 2 con trỏ ở cuối 2 string
        - Carry lúc này cũng khác, carry += a[i--] - '0'; res += carry % 2 + '0'; ,tương tự b - tức là cộng giá trị của nó lại
        rồi xem nếu chẵn (0 và 0 hoặc 1 và 1) thì res + 0
        - Lúc này carry /= 2 là được 
        => O(max(abs(a), abs(b)))
*/