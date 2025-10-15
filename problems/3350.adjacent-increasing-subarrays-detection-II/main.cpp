#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int lgth = 1, prevLgth = 0, res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) lgth++;
            else {
                res = max({res, lgth/2, min(lgth, prevLgth)});
                prevLgth = lgth;
                lgth = 1;
            }
        }

        return max({res, lgth/2, min(lgth, prevLgth)});
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int res = sol.maxIncreasingSubarrays(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giống như bài trước, mỗi lần duyệt qua mà tăng thì cứ tăng cnt lên
    - Cho đến khi gặp nhỏ hơn thì có 2 trường hợp:
        + Trường hợp 1 là trong cnt số vừa rồi có thể chia đôi để lấy được 2 mảng liên tiếp tăng dần, khi đó res là cnt/2
        + Trường hợp 2 là lần tính số lượng phần tử trong mảng tăng trước lớn hơn cnt hiện tại, hoặc ngược lại
        khi này ta lấy min của 1 trong 2 lần tính
*/