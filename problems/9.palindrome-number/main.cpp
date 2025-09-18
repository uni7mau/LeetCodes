#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// ----------------------Solution here---------------------
class Solution {
public:
    // bool isPalindrome(int x) {
    //     if (x < 0) return false;
    //     if (x == 0) return true;
    //     vector<int> str;
    //     int xLength = floor(log10(x)) + 1;
    //     // Nếu là chẵn vd 4 số thì chia 2 là 2 số, nếu lẻ vd 5 số thì chia 2 là 2 số.
    //     // Tức là duyệt đến length / 2, nó sẽ chưa duyệt đến phần tử giữa
    //     for (int i = 0; i < (xLength / 2); i++) { 
    //         int dv = x % 10;
    //         x /= 10;
    //         str.push_back(dv);
    //     }

    //     // Nếu độ dài lẻ thì bỏ qua phần tử giữa
    //     int j = (xLength % 2 == 1) ? (x /= 10, xLength / 2 + 1) : (xLength / 2);

    //     for (j; j < xLength; j++) {
    //         int dv = x % 10;
    //         x /= 10;    
    //         if (dv != str[xLength - 1 - j]) return false;
    //     }

    //     return true;
    // }

    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long rev = 0, num = x;
        while (num) {
            rev = rev*10 + num%10;
            num /= 10;
        }

        return rev == x;
    }
};
//---------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    Solution sol;
    // --------------------Input, Output here----------------------
    int x = -141;
    bool ans = sol.isPalindrome(x);
    cout << ans;
    //-----------------------------------------------------
}
#endif

/* Nháp ở dưới đây
    - Giải thích các thông tin
        + Là số Palindrome nếu số này đọc ngược và xuôi là như nhau
        + Nếu là xâu thì dễ làm rồi
    - Các ràng buộc cần để ý
        + Số cho vào khá là to -2^31 <= x <= 2^31 - 1 nên dùng long lưu được từ -+2^63
        + Nếu làm được mà không cần chuyển sang xâu ký tự thì tốt
    
    -> Nếu làm bằng xâu:
        - Chia cho 10 đến khi còn lại số 0
        - Các kết quả sau khi chia sẽ trở thành ký tự mới và cho vào mảng mới
        - So sánh các số từ giữa ra ngoài cùng bên trái lúc chia: khi đến giữa 
        thì so sánh số đó với số ở vị trí của phần tử đối diện mà đã lưu trong mảng)
        => Cách này làm được trong O(n) cũng thỏa mãn không dùng string nhưng mà 
        có gì đó sai sai, cũng hơi rườm rà
    -> Nếu chuyển ngôn ngữ sang python rồi dùng cái [::-1] thì tốt rồi
    -> Cách hay hơn tí là tạo 1 số mới rồi chia được bao nhiêu cho vào hết với
    cách chia giống như cách 1 đến khi duyệt hết thì so sánh với x là xong
*/
