#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (nums[j] == nums[j-1] && j < k) j++;
                    while (nums[k] == nums[k+1] && i < k) k--;
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
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = sol.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << "Bo ba so thu " << i + 1 << ":" << "\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Ba su be so";
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho mảng các số, tìm 3 số trong đó tổng lại = 0
    -> Dở nhất là for 3 lần
    -> Nếu tính hết trường hợp các cặp rồi lưu tổng thì quá phức tạp
    -> Sắp xếp tăng dần mất O(nlog(n)) sau đó duyệt bằng 3 con trỏ
        - Duyệt slide window với left tăng dần:
            + Nếu mà sum > 0 thì lui right lại
            + Nếu < 0 thì tăng mid lên
            + Đảm bảo không lặp giá trị
*/