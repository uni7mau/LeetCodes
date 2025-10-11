#include <bits/stdc++.h>

#define Shelter main
typedef long long ll;

using namespace std;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b)*b;
}

Shelter() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> demon(n+1);
        vector<int> link(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> demon[i];
            link[demon[i]]++;
        }

        queue<int> q;
        vector<bool> removed(n+1, false);

        for (int i = 1; i <= n; i++) {
            if (link[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            removed[u] = true;
            int v = demon[u];
            link[v]--;
            if (link[v] == 0) q.push(v);
        }

        ll res = 1;
        vector<bool> visited(n+1, false);
        for (int i = 1; i <= n; i++) {
            if (!removed[i] && !visited[i]) {
                int cnt = 0, x = i;
                while (!visited[x]) {
                    visited[x] = true;
                    x = demon[x];
                    cnt++;
                }
                res = lcm(res, cnt);
            }
        }

        cout << res << "\n";
    }

    
}
