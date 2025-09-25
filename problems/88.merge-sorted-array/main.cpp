#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Cách 1:
        // if (m == 0) { nums1 = nums2; return; }
        // if (n == 0) return;
        
        // vector<int> res;

        // int i = 0, j = 0;
        // while (i < m && j < n) {
        //     if (nums1[i] <= nums2[j]) {
        //         res.push_back(nums1[i]);
        //         i++;
        //     } else if (nums1[i] > nums2[j]) {
        //         res.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while (i < m) {
        //     res.push_back(nums1[i]);
        //     i++;
        // }
        // while (j < n) {
        //     res.push_back(nums2[j]);
        //     j++;
        // }

        // nums1 = res;

        // return;

        // Cách 2:
        int i = m-1, j = n-1, k = m + n - 1;

        while (j >= 0) {
            // Số nào lớn hơn thì lấy số đó ghi đè xuống cuối nums1
            if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    sol.merge(nums1, 3, nums2, 3);
    for (int i = 0 ; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích thông tin:
        + Cho 2 mảng a, b đã sắp xếp không giảm và m, n là số lượng phần tử phần tử của mảng a, b tương ứng
        + Trong đó mảng a thiếu b phần tử
        + Gộp 2 mảng vào mảng a theo thứ tự không giảm
    - Các ràng buộc cần lưu ý:
        + Số lượng phần tử mỗi mảng không quá 200
        + Giá trị của số tối đa vào khoảng 10^9 -> không quá int
    -> Sử dụng 2 con trỏ rồi so sánh 
    Cách 1 là tạo mảng mới, dùng cách trên rồi gán nums1 = res;
    Cách 2 là tư duy ngược: so sánh giá trị nào to nhất cho xuống cuối mảng 1, vừa không trùng vừa tiết kiệm bộ nhớ
*/