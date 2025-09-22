#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] > target) end = mid-1;
            else if (nums[mid] < target) start = mid+1;
            else return mid;
        }

        return end+1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int res = sol.searchInsert(nums, target);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Bài toán cho số target và mảng n số
        + Tìm vị trí nhét target vào
    - Các ràng buộc cần lưu ý:
        + Độ dài mảng tối đa 10^4
        + Số từ -10^4 -> 10^4
        + Mảng chứa các số tăng dần, khác nhau
        + Giải trong O(logn)
    -> Binary search:
        - Có left, mid, right -> lấy giữa để xét, nếu nhỏ hơn target thì lấy left = mid+1,
        lớn hơn target thì right = mid-1, nếu bằng thì return
*/