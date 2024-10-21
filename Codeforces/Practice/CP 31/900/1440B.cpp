#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n,k;
        cin >> n >> k;
        lli z = n * k;
        vector<lli> a(z);
        for(lli i = 0;i < z ;i++) cin >> a[i];
        lli med = (n&1) ? n/2 + 1 : n/2;
        lli j = (n & 1) ? z - med : z - 1 - med;
        lli ans = 0;
        while(k--){
            // cout << a[j] << " ";
            ans += a[j];
            j -= (n & 1) ? med : med + 1;
        }
        // cout << endl;
        cout << ans << endl;
    }
}
