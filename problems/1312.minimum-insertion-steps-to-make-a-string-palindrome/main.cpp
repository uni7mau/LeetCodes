#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int lcs(string s1, string s2, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }

    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.length();

        return n - lcs(s, s2, n);
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "mbadm";
    int res = sol.minInsertions(s);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

- Đề cho 1 chuỗi, có thể chèn bất cứ ký tự nào vào sao cho cuối cùng ra 1 chuỗi đọc xuôi hay ngược đều như nhau, số bước chính là output.
- Dùng dp lưu số lượng phần tử giống nhau với 2 chuỗi xuôi ngược, số lượng giống nhau của 2 chuỗi này nếu dùng length - đi thì ra output.
- Chạy 2 vòng for, gặp trùng thì + 1 so với khi so sánh currLength - 1, không thì so sánh xem lấy ký tự mới có cho ra kết quả tốt hơn so
với không lấy không bằng cách lấy max giữa j-1 (không lấy ký tự s) và i-1 (không lấy ký tự sReverse)
- Mô phỏng: mbadm <-> mdabm

- - m b a d m
- 0 0 0 0 0 0
m 0 1 1 1 1 1
d 0 1 1 1 2 2
a 0 1 1 2 2 2
b 0 1 2 2 2 2
m 0 1 2 2 2 3

*/