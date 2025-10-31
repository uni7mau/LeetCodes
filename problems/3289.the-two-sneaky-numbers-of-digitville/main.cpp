#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        // Cách 1:
        // map<int, int> check;
        // for (int i = 0; i < nums.size(); i++) {
        //     check[nums[i]]++;
        // }

        // vector<int> res;
        // for (auto x : check) {
        //     if (x.second > 1) {
        //         res.push_back(x.first);
        //     }
        // }

        // return res;

        // Cách 2:
        vector<bool> check(nums.size(), false);
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (check[nums[i]]) {
                res.push_back(nums[i]);
            } else {
                check[nums[i]] = true;
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
    vector<int> nums = {0, 1, 1, 0};
    vector<int> res = sol.getSneakyNumbers(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Bài này chỉ có 2 số xuất hiện 2 lần, các số còn lại 1 lần nên không dùng map sẽ nhanh hơns
*/