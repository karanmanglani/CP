#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n, m;
        cin >> n >> m;
        string x, y;
        cin >> x >> y;

        if (x == y) {
            cout << "YES" << endl;
            continue;
        }

        if (n == 1 && m == 1 && x != y) {
            cout << "NO" << endl;
            continue;
        }

        if (n < m) {
            cout << "NO" << endl;
            continue;
        }

        vector<char> p, q;
        bool flag = (x[0] == 'A') ? false : true;

        for (lli i = 0; i < n; i++) {
            if (flag && x[i] == 'B') {
                p.push_back('B');
                flag = false;
            } else if (!flag && x[i] == 'A') {
                p.push_back('A');
                flag = true;
            }
        }

        flag = (y[0] == 'A') ? false : true;

        for (lli i = 0; i < m; i++) {
            if (flag && y[i] == 'B') {
                q.push_back('B');
                flag = false;
            } else if (!flag && y[i] == 'A') {
                q.push_back('A');
                flag = true;
            }
        }

        if (p != q) {
            cout << "NO" << endl;
            continue;
        }

        vector<lli> u, v;
        flag = (x[0] == 'A') ? true : false;
        lli count = 0;

        for (lli i = 0; i < n; i++) {
            if (flag && x[i] == 'A') {
                count++;
            } else if (!flag && x[i] == 'A') {
                u.push_back(count);
                count = 1;
                flag = true;
            } else if (flag && x[i] == 'B') {
                u.push_back(count);
                count = 1;
                flag = false;
            } else if (!flag && x[i] == 'B') {
                count++;
            }
        }
        u.push_back(count);

        flag = (y[0] == 'A') ? true : false;
        count = 0;

        for (lli i = 0; i < m; i++) {
            if (flag && y[i] == 'A') {
                count++;
            } else if (!flag && y[i] == 'A') {
                v.push_back(count);
                count = 1;
                flag = true;
            } else if (flag && y[i] == 'B') {
                v.push_back(count);
                count = 1;
                flag = false;
            } else if (!flag && y[i] == 'B') {
                count++;
            }
        }
        v.push_back(count);

        bool valid = true;

        for (lli i = 0; i < u.size(); i++) {
            if (u[i] < v[i] || (u[i] - v[i]) % 2 != 0) {
                valid = false;
                break;
            }
        }

        if (u.size() == 1 && u[0] != v[0]) {
            cout << "NO" << endl;
        } else if (u.size() == 1 && u[0] == v[0]) {
            cout << "YES" << endl;
        } else if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}