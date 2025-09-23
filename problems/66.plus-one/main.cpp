#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Cách 1: (mất não)
        // int n = digits.size();
        // if (digits[n-1] < 9) {
        //     digits[n-1]++;
        // } else {
        //     digits[n-1] = 0;
        //     int lft = 1;
        //     for (int i = n-2; i >= 0; i--) {
        //         if (digits[i] == 9) digits[i] = 0;
        //         else if (lft == 1){
        //             digits[i]++;
        //             lft = 0;
        //             break;
        //         }
        //     }
        //     if (lft == 1) {
        //         digits.push_back(0);
        //         for (int i = n-1; i >= 1; i--) {
        //             digits[i] = digits[i-1];
        //         }
        //         digits[0] = 1;
        //     }
        // }

        // return digits;

        // Cách 2:
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }
        digits.resize(digits.size() + 1);
        for (int i = digits.size()-1; i >= 1; i--) {
            digits[i] = digits[i-1];
        }
        digits[0] = 1;

        return digits;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> digits = {9, 9, 9};
    sol.plusOne(digits);
    for (int i = 0; i < digits.size(); i++) {
        cout << digits[i] << " "; 
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Đề cho một số lớn được biểu diễn qua vector
        + Sau khi giá trị của số đó + 1
        + Hãy trả về giá trị đó dưới dạng vector
    - Ràng buộc cần lưu ý: 
        + Độ dài tối đa là 100
        + Ký tự gồm số từ 0 -> 9
    -> Cách 1: 
        - Check ký tự cuối:
            + Nếu nhỏ hơn 9 thì +1 rồi in ra
            + Nếu không thì:
                <> Gán là 0, lấy phần thừa là 1
                <> Xét các phần tử trước đó, nếu < 9 thì cộng rồi break
                <> Nếu là 9 thì ghi vào là 0, lấy phần dư là 1 cho đến khi hết phần tử như vậy hoặc đến đầu
                <> Cuối cùng khi duyệt hết phần tử rồi thì kiểm tra xem còn dư không, nếu dư thì chuyển hết
                các phần tử về cuối, còn phần tử đầu thì ghi thêm giá trị dư
        => O(n)

    -> Cách 2:
        - Gọn hơn:
            + Xét từ cuối lên, nếu khác 9 thì + rồi return
            + Không thì cho phần tử là 0
            + Cho đến đầu nếu thoát khỏi vòng for thì đẩy phần tử xuống cuối hoặc tạo mảng mới rồi gắn 1 tùy
*/