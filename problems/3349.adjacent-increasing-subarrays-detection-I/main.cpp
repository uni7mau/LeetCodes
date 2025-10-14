#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (nums.size() < 2*k) return false;

        int i = 0;
        int check = 0;
        while (i < nums.size()) {
            int cnt = 1;
            int j = i+1;
            while (j < nums.size() && nums[j] > nums[j-1]) {
                cnt++;
                j++;
            }
            if (cnt >= 2*k) {
                return true;
            } else if (cnt >= k) {
                if (check == 1) return true;
                else check = 1;
            } else {
                check = 0;
            }

            i = j;
        }

        return false;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {6,13,-17,-20,2};
    int k = 3;
    bool res = sol.hasIncreasingSubarrays(nums, k);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Đề cho 1 dãy số
    - Tìm xem trong dãy số có 2 dãy con nào tăng liên tục không
    - Tăng không tính =
    -> thử dùng while với 2 biến tăng thử: ok khỏi sửa
*/