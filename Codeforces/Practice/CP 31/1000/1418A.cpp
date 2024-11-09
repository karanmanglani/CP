#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli x , y , k;
        cin >> x >> y >> k;
        lli torch = 1, coal = 0;
        lli tn = (y+1)*k;
        lli ans = ((tn -1) % (x-1) == 0) ? (tn-1)/(x-1) : 1 + (tn-1)/(x-1);
        ans += k;
        cout << ans << endl;
        
    }
    return 0;
}
