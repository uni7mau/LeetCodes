#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n + 1, 0);
        steps[0] = 1; steps[1] = 1;

        for (int i = 2; i <= n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }

        return steps[n];
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 3;
    int res = sol.climbStairs(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho n là số bước của cầu thang (số bậc)
        + Mỗi lần được bước 1 hoặc 2 bậc
        + Hỏi bao nhiêu bước di chuyển thì lên được đỉnh
    - Các ràng buộc cần lưu ý:
        + n tối đa 45
    -> Dynamic programming cơ bản:
        - Bước 1 là gắn hết các phần tử đầu (tức là đề cho 1 hoặc 2 bước thì gán 1 là 1 (bước) và 0 là 1)
        - Bước 2 là di chuyển lên, số cách đến bước i bằng số cách đến bước i-1 hoặc i-2 (từ vị trí đó bước lên 1 hoặc 2 bước)
*/