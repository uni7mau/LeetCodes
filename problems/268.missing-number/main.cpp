#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Cách 1:
        // set<int> s;
        // for (int i = 0; i < nums.size(); i++) {
        //     s.insert(nums[i]);
        // }
        
        // int prev = -1;
        // for (auto x : s) {
        //     if (x-prev > 1) {
        //         return x-1;
        //     }
        //     prev = x;
        // }
        
        // return prev+1;

        // Cách 2:
        vector<int> v(nums.size()+1, -1);
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                return i;
            }
        }
        
        return 0;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int res = sol.missingNumber(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cách 1: dùng set, sau đó duyệt các phần tử xem phần tử nào - phần tử trước mà > 1 thì ngay trước nó là phần tử thiếu
    - Cách 2: dùng mảng thường thôi, trả về phần tử trong mảng không được đánh dấu
*/