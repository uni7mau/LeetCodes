#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string res; 

        if ((numerator < 0) ^ (denominator < 0)) res += '-';
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        res += to_string(n / d);
        if (n % d == 0) return res;
        n = (n%d)*10;
        res += '.';

        map<int, int> mp;
        while (n != 0) {
            if (mp.count(n)) {
                res.insert(mp[n], "(");
                res += ")";
                break;
            }
            mp[n] = res.size();

            int nextRight = (int)(n/d);
            res += '0' + nextRight;
            n -= nextRight*d;
            if (n != 0 && n < d) n *= 10;
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    // int numerator = 8, denominator = 965;
    int numerator = 1, denominator = -1;
    string res = sol.fractionToDecimal(numerator, denominator);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin: 
        + Cho 2 số nguyên tử, mẫu
        + In kết quả của phân số này theo dạng thập phân
    - Ràng buộc cần lưu ý
        + Hai số tối đa là cận của int (nhưng mà test case vẫn dùng phần tử quá int, khó hiểu thật đấy)
        + Mẫu chắc chắn khác 0
        + Kết quả có số dư nhiều quá thì tối đa là 10^4 phần tử
        + Nếu có nhiều kết quả, trả về bất cứ kết quả nào (??? how)
        + Nếu kết quả bị lặp thì đóng hòm thằng bị lặp (ví dụ lặp tuần tự 2 thì là (2), lặp 12312312... thì là (123))
    -> Ví dụ chia bằng tay (tiểu học còn biết):
        5 | 2
       _4_|_2_._5___
        1 |
       10 |
        0 |

        - Chia số hiện tại cho denom, lấy giá trị
        - Nếu không chia hết mà chưa phải 0 thì mượn số 0, kết quả lùi ra 1 đơn vị
        - Sau đó chia tiếp lấy giá trị
        - Cứ thế cho đến khi = 0;
        - Nói chung là như giải tay, chỉ khác là cách biết vị trí mà nó trùng để đóng mở ngoặc:
            + Kiểm tra số hiện tại có ở trong map hay chưa, nếu có rồi thì insert mở ngoặc vào đó
            + Sau đó cộng thêm đóng ngoặc ở cuối rồi break return
            + Nếu không có trong map thì trong mỗi lượt lặp ta ghi lại vị trí của số
        <!> Nếu bạn thắc mắc có những số 0,002831823... thì cái phần tử 0 thứ 2 hoặc 2 thứ 2 trong mảng phải không được đóng ngoặc
        nhưng thật ra chúng ta đã điều kiện phần số chia chứ không phải kết quả của nó, cho nên phần chia bên trái mà đã từng chia
        rồi thì đương nhiên các phần sau cũng ra kết quả y hệt
        => O(n)
*/