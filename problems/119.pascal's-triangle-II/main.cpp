#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> next;
            next.push_back(0); for (int j = 0; j < res.size(); j++) next.push_back(res[j]); next.push_back(0);
            res.clear();

            for (int j = 0; j < i; j++) {
                res.push_back(next[j] + next[j+1]);
            }
            res.push_back(1);
        }

        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int numRows = 5;
    vector<int> res = sol.getRow(numRows);
    for (int i = 0; i < numRows; i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Làm giống bài 118 thì nó bị phí space, vì vậy chúng ta sẽ làm theo cách của bài 118 nhưng là bản python

    -> Làm xong thấy không tiết kiệm cho lắm nhỉ
*/