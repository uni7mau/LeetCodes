#include <bits/stdc++.h>
#define Shelter main
using namespace std;

// -------------------------Struct here------------------------

// ------------------------------------------------------------

// ------------------------Solution here-----------------------
class MyStack {
private:
    queue<int> q;

public:
    MyStack() { }
    
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
// ------------------------------------------------------------

#ifndef ONLINE_JUDGE
Shelter() {
    MyStack sol;
    // --------------------Input, Output here----------------------

    // ------------------------------------------------------------
}
#endif

/* Nháp ở dưới đây

*/