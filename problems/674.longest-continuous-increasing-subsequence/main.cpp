#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, currLgth = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] > 0) {
                currLgth++;
                res = max(res, currLgth);
            } else currLgth = 1;
        }
        
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums = {1,3,5,4,7};
    int res = sol.findLengthOfLCIS(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/