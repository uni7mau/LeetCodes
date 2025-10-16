#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int res = nums[0] + nums[1] + nums[2], closet = abs(target - res);
        for (int i = 0; i < nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < closet) {
                    closet = abs(target - sum);
                    res = sum;
                }
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return sum;
                }
            }
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    int res = sol.threeSumClosest(nums, target);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho 3 số với 1 target, tìm bộ 3 sú sao cho ~ 1 bê xô rồi trả về tổng 3 sú đó
    -> Giống bài trước, dùng 3 con trỏ nhưng thay điều kiện cuối thành return luôn và thêm 1 if ở đầu cập nhật min
    => Lại là O(n^2)
*/