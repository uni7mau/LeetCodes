#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        int pos = 0, cnt = 0;
        while (pos < nums.size()) {
            if (nums[pos] != val) {
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
    vector<int> nums = {3, 2, 2, 3};
    int res = sol.removeElement(nums, 3);
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
        + Cho mảng nums và số val
        + Cần xóa hết val trong nums, trả về size và mảng đã xóa
        + Phần bị khuyết điền số gì cũng được
    - Các ràng buộc cần chú ý:
        + Số lượng tối đa là 100 số
        + Số khoảng 50
        + Val khoảng 100
    -> Tiểu học quá, quên bài này đi
*/