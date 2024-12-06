#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    // your code goes here
    lli t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;
        vector<lli> a(n);
        lli mn = 0, mx = 0;
        for (lli i = 0; i < n; i++) {
            cin >> a[i];
            long double x = (long double)a[i] / k; 
            mn += floor(x);
            mx += ceil(x); 
        }
        cout << ((mn <= 0 and mx >= 0) ? "YES" : "NO") << endl;
    }
}
