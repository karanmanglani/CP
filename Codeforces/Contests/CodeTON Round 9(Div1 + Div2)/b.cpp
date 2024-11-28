#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        lli n = a.size();
        
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        
        bool fnd = false;
        string ans;

        for (lli i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                ans = a.substr(i, 2);
                fnd = true;
                break;
            }
        }

        if (!fnd) {
            for (lli i = 0; i < n - 2; i++) {
                set<char> s = {a[i], a[i + 1], a[i + 2]};
                if (s.size() == 3) {
                    ans = a.substr(i, 3);
                    fnd = true;
                    break;
                }
            }
        }

        if (fnd) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
