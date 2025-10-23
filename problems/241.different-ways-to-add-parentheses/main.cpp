#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i+1));
                for (int x : s1) {
                    for (int y : s2) {
                        if (op == '+') res.push_back(x+y);
                        else if (op == '-') res.push_back(x-y);
                        else if (op == '*') res.push_back(x*y);
                    }
                }
            }
        }

        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string expression = "2*3-4*5";
    vector<int> res = sol.diffWaysToCompute(expression);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    
*/