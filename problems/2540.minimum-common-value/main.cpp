#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < nums1.size() && pos2 < nums2.size()) {
            if (nums1[pos1] < nums2[pos2]) pos1++;
            else if (nums1[pos1] > nums2[pos2]) pos2++;
            else return nums1[pos1];
        }
        
        return -1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums1 = {1,2,3,6};
    vector<int> nums2 = {2,3,4,5};
    int res = sol.getCommon(nums1, nums2);
    cout << res << " ";
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/