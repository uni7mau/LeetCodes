#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
private:
    string change_to_bit(int num) {
        string res = "";
        while (num != 0) {
            res += '0' + (num%2);
            num /= 2;
        }
        return res;
    }
    string flip(string num) {
        string res = "";
        for (int i = num.length() - 1; i >= 0; i--) {
            int last = num[i]-'0';
            if (last == 0) res += '1';
            else res += '0';
        }
        return res;
    }
    int change_to_int(string bitNum) {
        int res = 0;
        for (int i = 0; i < bitNum.length(); i++) {
            int pos = bitNum.length()-i-1;
            if (bitNum[pos] == '1') {
                res += pow(2, i);
            }
        }
        return res;
    }
public:
    int findComplement(int num) {
        string bitNum = change_to_bit(num);
        string reversedBitNum = flip(bitNum);
        int res = change_to_int(reversedBitNum);
        return res;
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int num = 5;
    int res = sol.findComplement(num);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/