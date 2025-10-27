#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    void KMP(string s, vector<int> &lp) {
        int i = 0, j = 1;
        while (j < s.length()) {
            if (s[i] == s[j]) {
                i++;
                lp[j] = i;
                j++; 
            } else {
                if (i == 0) j++;
                else i = lp[i-1];
            }
        }
    }
public:
    string shortestPalindrome(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        string newStr = s + "#" + tmp;
        vector<int> lp(newStr.length(), 0);
        KMP(newStr, lp);

        int pos = lp[newStr.length()-1];
        string rvAddStr = s.substr(pos);
        reverse(rvAddStr.begin(), rvAddStr.end());

        return rvAddStr + s;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "abcd";
    string res = sol.shortestPalindrome(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho chuỗi str, có thể chuyển chuỗi str thành palindrome bằng cách thêm 1 ký tự vào đầu chuỗi
    - Được phép thực hiện nhiều lần thêm
    - Trả về chuỗi ngắn nhất là palindrome
    ->
        - Tìm số lượng chữ thiếu từ chuỗi s ban đầu
        - Sau đó cắt từ đuôi chuỗi s dán lên
        - Dùng KMP algorithm
*/