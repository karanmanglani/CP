#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        lli n,k;
        cin >> n >> k;
        if(!(n & 1 )) {
            cout << "YES" << endl;
            continue;
        }else if(!((n - k)&1 )and (n-k) > 1){
            cout << "YES" << endl;
            continue;
        }
        lli x = n/k;
        x *= k;
        cout << ((n-x)&1 ? "NO" : "YES") << endl;
    }
    
    return 0;
}