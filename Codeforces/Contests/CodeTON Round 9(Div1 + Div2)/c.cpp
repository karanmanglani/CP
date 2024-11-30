#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli a;
    cin >> a;
    while (a--) {
        lli b, c;
        cin >> b >> c;
        lli d = 1;
        while (d <= b) d *= 2;
        d = min(d, c);
        lli e = 0;
        for (lli f = 1; f <= d; f++) {
            lli g = f ^ b;
            if (g == 0) continue;
            if (b % g == 0 || f % g == 0) e++;
        }
        cout << e << endl;
    }
    return 0;
}