#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; prev++) {
                if (abs(prev - curr) <= k) {
                    best = max(best, dp[prev]);
                }
            }
            dp[curr] = max(dp[curr], best+1);
            res = max(res, dp[curr]);
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string s = "acfgbd"; int k = 2;
    int res = sol.longestIdealString(s, k);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Mỗi ký tự duyệt 36, à không là 26 lần để xem chiều dài tốt nhất là bao nhiêu
    - sau đó cập nhật dp cho ký tự hiện tại là chiều dài tốt nhất + 1
*/