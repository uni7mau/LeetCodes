#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int change = original;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == original) {
                change = max(original, findFinalValue(nums, original*2));
            }
        }

        return change;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {5,3,6,1,12};
    int original = 3;
    int res = sol.findFinalValue(nums, original);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/