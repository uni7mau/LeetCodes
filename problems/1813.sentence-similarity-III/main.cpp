#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> split1, split2;

        stringstream s1(sentence1), s2(sentence2);
        string tmp;
        while (s1 >> tmp) split1.push_back(tmp);
        while (s2 >> tmp) split2.push_back(tmp);

        if (split1.size() < split2.size()) swap(split1, split2);
        
        int i = 0, j = 0;
        while (i < split2.size() && split1[i] == split2[i]) i++;
        while (j < split2.size() && split1[split1.size()-1-j] == split2[split2.size()-1-j]) j++;
        
        return i + j >= split2.size();
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    string sentence1 = "Hello Jane";
    string sentence2 = "Hello my name is Jane";
    bool res = sol.areSentencesSimilar(sentence1, sentence2);
    cout << res;
    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Cho vào mảng chia thành các chữ khác nhau
    - Xét trường hợp mẫu là số lượng chữ của sentence1 lớn hơn sentence2
    - Cho 1 con trỏ tăng theo số lượng chữ nhiều hơn, tăng đến khi hết chữ giống.
    - Cho 1 con trỏ nữa để duyệt từ cuối lên
    - Nếu tổng 2 con trỏ này (tổng các phần tử giống nhau) lớn hơn số lượng chữ của sentence thứ 2 (nhỏ hơn) tức là có thể thay được
*/