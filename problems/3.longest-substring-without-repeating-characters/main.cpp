#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSaw;
        int mxLength = 0, l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (lastSaw.count(s[r]) == 0 || lastSaw[s[r]] < l) mxLength = max(mxLength, r-l+1);
            else l = lastSaw[s[r]] + 1;
            lastSaw[s[r]] = r;
        }

        return mxLength;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "abcabcbb";
    int res = sol.lengthOfLongestSubstring(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    * Giải thích thông tin:
        - Cho một chuỗi ký tự
        - Hãy tìm chuỗi con mà có độ dài chuỗi dài nhất sao cho chuỗi đó chứa các ký tự khác nhau
    -> Nếu tìm được ký tự đã có trước đó thì độ dài cập nhật bằng vị trí của ký tự đã thấy + 1 tới vị trí hiện tại
    
*/