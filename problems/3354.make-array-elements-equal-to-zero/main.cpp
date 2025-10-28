#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    int sol(vector<int> nums, int pos, int firstDir) {
        int dir = firstDir;

        while (pos >= 0 && pos < nums.size()) {
            if (nums[pos] > 0) {
                nums[pos]--;
                dir *= -1;
            }
            pos += dir;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) return 0;
        }

        return 1;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                res += sol(nums, i, 1);
                res += sol(nums, i, -1);
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
    vector<int> nums = {2,3,4,0,4,1,0};
    int res = sol.countValidSelections(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/