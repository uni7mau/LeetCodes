#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.length(); i++) 
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) 
                str.push_back(tolower(s[i]));
        
        for (int i = 0; i < str.length()/2; i++)
            if (str[i] != str[str.length()-1-i])
                return false;

        return true;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = ".,";
    bool res = sol.isPalindrome(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho chuỗi a
        + Hỏi sau khi convert từ uppercase sang lowercase, xóa mọi ký tự "non-alphanumeric"
        + Đọc từ cuối lên đầu và từ đầu xuống cuối có giống nhau không
    - Các ràng buộc cần lưu ý:
        + Độ dài chuỗi tối đa khoảng 2*10^5
        + s chỉ chứa các ký tự ASCII có thể in ra được
    -> Giống bài toán kiểm tra xâu đối xứng nhưng thêm 1 vài bước nhỏ
        - Chuyển đổi hết theo yêu cầu và bỏ khoảng trống thì chỉ mất có O(n)
        - Sau đó trở thành bài toán kiểm tra xâu đối xứng bình thường
        - Cách làm sau đó là xét từ giữa ra 2 bên
        => O(n)
*/