#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int res = 0, mxFre = 0;
        for (auto x : mp) {
            if (x.second == mxFre) {
                res += x.second;
            } else if (x.second > mxFre) {
                res = x.second;
                mxFre = x.second;
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
    vector<int> nums = {1};
    int res = sol.maxFrequencyElements(nums);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    
*/