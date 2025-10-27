#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int j = 0; j < n; j++) dp[0][j] = grid[0][j];

        for (int i = 1; i < n; i++) {   
            for (int j = 0; j < n; j++) {
                int currMn = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k != j) currMn = min(currMn, dp[i-1][k] + grid[i][j]);
                    dp[i][j] = currMn;
                }   
            }
        }

        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp[n-1][j]);
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int res = sol.minFallingPathSum(grid);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cách dễ nhất là lấy 3 vòng for
    - Bắt đầu từ dòng thứ 2, giá trị của ô đang duyệt sẽ là min của tất cả trường hợp mà: (dp[i-1][j] + currVal)
    - Chỉ cần thêm điều kiện là cột xét trong vòng duyệt khác cột của value hiện tại
*/