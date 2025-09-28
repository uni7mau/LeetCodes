#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = nums.size()-1; i >= 2; i--) {
            if (nums[i-1] + nums[i-2] > nums[i]) {
                return nums[i] + nums[i-1] + nums[i-2];
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
    vector<int> nums = {1,2,1,10};
    int res = sol.largestPerimeter(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Informs:
        + Cho mảng nums
        + Trả về kết quả là chu vi tam giác to nhất
    - Constraints:
        + Giá trị không vượt quá 10^6
        + Số lượng phần tử từ 3 đến 10^4

    -> Chu vi tam giác là a + b + c
        - Còn để tạo thành tam giác thì a + b > c
        - Vậy thì sort, sau đó 3 thằng liên tiếp duyệt từ cuối sẽ quyết định có to nhất hay không
*/