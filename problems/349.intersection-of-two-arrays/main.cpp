#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }

                i++;
                j++;
            } 
            else if (nums1[i] < nums2[j]) i++;
            else j++; 
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> res = sol.intersection(nums1, nums2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho 2 mảng số, trả về mảng chứa các phần tử giao nhau
    -> 2 con trỏ => O(n1*log(n1) + n2*loh(n2))
*/