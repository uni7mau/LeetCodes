#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;

        for (int i = 0; i < s.length(); i++) {
            if (mps.find(s[i]) == mps.end()) {
                mps[s[i]] = i;
            }

            if (mpt.find(t[i]) == mpt.end()) {
                mpt[t[i]] = i;
            }

            if (mps[s[i]] != mpt[t[i]]) {
                return false;
            }
        }

        return true;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "egg", t = "add";
    bool res = sol.isIsomorphic(s, t);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho 2 chuỗi s và t
        + Kiểm tra chuỗi này có là số isomorphic không
        + Là số mà thay chữ cái đó trong chuỗi thì có thể ra chuỗi thứ 2
        + Tức là thực hiện 1 lần mỗi chữ cái (chữ cái tương tự cũng bị thay đổi)
    - Các ràng buộc cần lưu ý:
        + Chuỗi dài tối đa 5*10^4
        + Chiều dài s bằng chiều dài t
        + Chỉ thuộc bảng ascii
    -> Nếu thay chữ cái mà chuỗi 1 bằng chuỗi 2 thì:
        - Vị trí là có quan trọng
        - Số lượng ký tự của 1 chữ cái bằng nhau thì nói lên được chuỗi này có khả năng thỏa mãn (đk cần)
        - Vị trí ký tự nếu so sánh thì so sánh theo cặp giá trị - vị trí, nếu 
        
        - Map thử lần 1: 
            + p-0, p-2; a-1; e-3; r-4
            + t-0, t-2; i-1; l-3; e-4
        - Đó là map theo 26 ký tự
        - Nếu đảo ngược lại thành value-key: 
            x
        
        - Tạo biến i = 0, currPos = 0, dùng while (currPos != s.length()):
            + Nếu khác tại vị trí thì thay bằng ký tự của chuỗi t[i], nhớ remem = s[i]
            + Nếu gặp lại phần tử đó thì thay
            + Kiểm tra nếu = thì break;
            + Nếu i == s.length() -> i = currPos++;
            x
    -> Nếu so sánh từng ký tự, ta cần biết ký tự hiện tại của chuỗi đã từng được đọc chưa, nếu vị trí của phần tử 
    trong cả 2 mảng mà lệch nhau (tức đã dùng ở chỗ khác) thì trả về 0 luôn
    Vd: foo - bar
        f-0, b-0
        o-1, a-1
        o-2, r-2
    -> Sai ở o thứ 2 vì khi kiểm tra thì thấy vị trí của nó ở s là 1 còn vị trí của nó ở t là 2 (o đã thay, 
    đến hiện tại cũng cần thay nhưng phần tử bên phải thì lại mới gặp lần đầu)
    Vd: faaca - barcs
        f-0, b-0
        a-1, a-1
        a-2, r-2
        c-3, c-3
        a-4, s-4
    -> Sai vì khi đến cuối so sánh bên s thấy a đã gặp ở 2, nhưng phần tử s mới gặp đầu tiên, nên không thay được
*/