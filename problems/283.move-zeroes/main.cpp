#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {0,1,0,3,12};
    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin: 
        + Đề cho n là số lượng phần tử, mảng n số nums
        + Trong mảng chứa các số 0, chuyển nó về cuối
    - VD: -> 0 1 0 3 12 -> 1 0 0 3 12 -> 1 0 0 3 12 -> 1 3 0 0 12 -> 1 3 0 0 12 -> 1 3 12 0 0
    -> 2 con trỏ
    => O(n)
*/