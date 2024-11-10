#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--){
        lli n,b,c;
        cin >> n >> b >> c;
        if(b != 0){
            lli ans = (n-c-1)/b;
            ans++;
            if(ans < 0) ans = 0;
            if(c >= n) ans = 0;
            ans = n - ans;
            cout << ans << endl;
        }else{
            if(n - c > 2) cout << -1 << endl;
            else {
                if( c >= n) cout << n << endl;
                else cout << n-1 << endl;
            }
        }
    }
}