#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int lengthOfLastWord(string s) {
        // Cách 1:
        stringstream ss(s);

        string word = "";
        int res = 0;
        while (ss >> word) {
            res = word.length();
        }

        return res;

        // Cách 2:
        int end = s.length()-1;

        while (end >= 0 && s[end] == ' ') end--;

        int start = end;
        while (start >= 0 && s[start] != ' ') start--;

        return end - start;        
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s =  "   fly me   to   the moon  ";
    int res = sol.lengthOfLastWord(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho chuỗi str
        + Trả về độ dài của chữ cuối cùng
    - Ràng buộc cần lưu ý:
        + Chuỗi str dài tối đa 10^4
        + s chỉ bao gồm ký tự tiếng anh và khoảng trống ' '
    -> Cách 1: dùng hàm string stream trong c++ 
    -> Cách 2: 
        + Tạo biến start, end
        + Duyệt từ cuối về, nếu str[i] là trống thì lùi end về, khi gặp ký tự thì thoát
        + Duyệt từ end đến khi hết gặp ký tự - tức là gặp khoảng trống, khi đó ta có start là vị trí trước đầu chữ
        + Kết quả là end - start
        => O(n)
*/