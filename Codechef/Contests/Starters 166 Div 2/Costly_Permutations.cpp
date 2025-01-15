#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

void dfs(vector<bool>& v, lli i, lli& sz, const vector<lli>& p) {
    v[i] = true;
    sz++;
    if (!v[p[i] - 1]) dfs(v, p[i] - 1, sz, p);
}

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<lli> p(n);
        for (auto& x : p) cin >> x;

        vector<bool> v(n, false);
        vector<lli> szs;

        for (lli i = 0; i < n; i++) {
            if (!v[i]) {
                lli sz = 0;
                dfs(v, i, sz, p);
                szs.push_back(sz);
            }
        }

        lli ans = 0;
        if (szs.size() > 1) {
            multiset<lli> s(szs.begin(), szs.end());
            while (s.size() > 1) {
                auto it = s.begin();
                lli a = *it;
                s.erase(it);
                it = s.begin();
                lli b = *it;
                s.erase(it);
                s.insert(a + b);
                ans += a + b;
            }
        }

        cout << ans << endl;
    }
}
