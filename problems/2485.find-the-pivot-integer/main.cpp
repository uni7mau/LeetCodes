#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    int sumInc(int n, int a1, int an) {
        return (n*(a1 + an))/2;
    }
public:
    int pivotInteger(int n) {
        int pivot = 1;
        while (pivot < n && sumInc(pivot, 1, pivot) < sumInc(n-pivot, pivot, n)) pivot++;

        if (sumInc(pivot, 1, pivot) == sumInc(n-pivot+1, pivot, n)) return pivot;
        return -1;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int n = 8;
    int res = sol.pivotInteger(n);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Tìm con số x sao cho từ sum[a, x] = sum[x, b]
    -> 1 con pivot
*/