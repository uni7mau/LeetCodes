#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {

priority_queue<int> smaller; // maybe some thing igg-er
priority_queue<int, vector<int>, greater<int>> bigger;

private:
    void insert(int val, int widw) {
        int biggest_in_smaller = smaller.top();
        if (biggest_in_smaller < val) {
            bigger.push(val);
            if (bigger.size() > widw/2) {
                smaller.push(bigger.top());
                bigger.pop();
            }
        } else {
            smaller.push(val);
            if (smaller.size() > (widw+1)/2) {
                bigger.push(smaller.top());
                smaller.pop();
            }
        }
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > 0) smaller.push(nums1[0]);
        else smaller.push(nums2[0]);

        for (int i = 1; i < nums1.size(); i++) {
            insert(nums1[i], nums1.size() + nums2.size());
        }
        for (int i = 0; i < nums2.size(); i++) {
            insert(nums2[i], nums1.size() + nums2.size());
        }

        if ((nums1.size() + nums2.size())%2 == 1) return smaller.top();
        return (smaller.top() + bigger.top()) / 2.0;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    double res = sol.findMedianSortedArrays(nums1, nums2);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho 2 cái priority queue trong đó 1 cái ngược, so sánh giá trị tiếp theo với 2 đầu của pq
    - Nếu nhỏ hơn thằng lớn thì insert vào thằng nhỏ ?? và ngược lại
    - Cách này áp dụng được cho cả bài toán với size thay đổi, với bài này thì widw cố định = size1 + size2
*/