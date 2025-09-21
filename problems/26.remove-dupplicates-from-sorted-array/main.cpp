#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res; res.push_back(nums[0]);
        int cnt = 1, pos = 0;

        while (pos < nums.size()) {
            if (nums[pos] > res.back()) {
                res.push_back(nums[pos]);
                cnt++;
            }

            pos++;
        }

        for (int i = pos; i < nums.size(); i++) {
            res.push_back(-1);
        }
        nums = res;

        return cnt;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {0};
    int res = sol.removeDuplicates(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho dãy số, đã sắp xếp không giảm, xóa các phần tử trùng của mảng rồi return số lượng phần tử không trùng
    - Ràng buộc cần lưu ý:
        + Mảng sắp xếp rồi thì phần tử sau không quan trọng
    -> Tạo mảng, cnt = 0, duyệt từ đầu đến cuối, phần tử hiện tại = phần tử cuối của mảng thì cnt++
        Đẩy hết mảng.size() - pos + cnt phần tử -1 vào
        In ra cnt
*/