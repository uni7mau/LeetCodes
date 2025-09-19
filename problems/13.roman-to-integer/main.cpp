#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// ----------------------Solution here---------------------
class Solution {
public:
    int romanToInt(string s) {
        int i = 0, res = 0;
        while (i != s.size()) {
            char curr = s[i];
            if (curr == 'M') res += 1000;
            if (curr == 'D') res += 500;
            if (curr == 'C') {
                if (s[i+1] == 'D') {
                    res += 400;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'M') {
                    res += 900;
                    i += 2;
                    continue;
                }
                res += 100;
            }
            if (curr == 'L') res += 50;
            if (curr == 'X') {
                if (s[i+1] == 'L') {
                    res += 40;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'C') {
                    res += 90;
                    i += 2;
                    continue;
                }
                res += 10;
            }
            if (curr == 'V') res += 5;
            if (curr == 'I') {
                if (s[i+1] == 'V') {
                    res += 4;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'X') {
                    res += 9;
                    i += 2;
                    continue;
                }
                res += 1;
            }

            i++;
        }

        return res;
    }
};
//---------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "MCMXCIV";
    int res = sol.romanToInt(s);
    cout << res;
    //-----------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Các ràng buộc cần để ý gồm:
        + Đề bài cho 1 chuỗi tương ứng 1 số duy nhất
        + Độ dài của chuỗi input là từ 1 đến 15 tức là từ I đến MMMMMMMMMMMMMMM (15 chữ khỏi đếm, sai thế nào được)
    - Giải thích các thông tin:
        + s là chữ la mã hợp lệ từ 1 đến 3999 (Không hiểu lắm, full M thì số to hơn nhiều)
        + I có thể đặt trước V(5) và X(10) để tạo ra 4/9 (IV và IX)
        + X ,, L ,, C -> 40/90 (XL và CL)
        + C ,, D ,, M -> 400/900 (CD và CM)
    -> Nếu nghĩ theo dạng thủ công thì:
        - Lấy ví dụ strTemp - temp = XXIV
            + Xét từ đầu đến cuối, khi gặp X thì là +10
            + Cho đến khi gặp I thì là +1
            + Nếu sau đó có số la mã lớn hơn thì chuyển I thành -1, số lớn vừa gặp là V thì +5
            + Tổng thành phần cuối là 4, hình như không thể có số la mã dạng nhỏ trước lớn lần thứ 2 đâu
            + Kết quả là tổng từ đầu đến cuối
        - Số lớn thì đứng trước, số nhỏ thì ở sau, kết thúc khi hết dãy hoặc gặp phần tử to hơn
            => Duyệt từ đầu đến cuối mỗi lần 1 ký tự, if ký tự = "ký tự la mã" thì chuyển thành giá trị (skip)
        - Nhìn kỹ ví dụ thì thấy tại ví dụ 3 MCMXCIV có ký tự C chèn giữa M mà có những ký tự sau nữa
        - Vậy thì duyệt tiếp, nhưng bước nhảy sẽ là i += 2 thay vì i++
        - Dùng while sẽ tiện hơn
        - Khi gặp 3 trường hợp I, X, C kia thì kiểm tra luôn số sau, nếu có lớn hơn thì += 2
        
*/