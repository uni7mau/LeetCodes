#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        
        for (int i = 0; i < nums.size()-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size()-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1, v = nums.size()-1;
                while (k < v) {
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[v];

                    if (sum > target) {
                        v--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[v]});
                        k++;
                        v--;

                        while (nums[k] == nums[k-1] && k < v) k++;
                        while (nums[v] == nums[v+1] && j < v) v--;
                    }
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
    vector<int> nums = {2, 2, 2, 2, 2};
    int target = 8;
    vector<vector<int>> res = sol.fourSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << "Bo 4 so thu " << i + 1 << ":" << "\n";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "4 su be so";
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Lại là 3 sú bê xô + 1 nhưng có cả target, còn gì vui hơn
    -> Thêm 1 vòng lặp so với các bài trước
        !Chú ý là giá trị tới 10^9 nên để sum là long
        => O(n^3)
        
*/