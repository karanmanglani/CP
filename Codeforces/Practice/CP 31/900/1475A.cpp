#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n;
        cin >> n;
        cout << ((n&(n-1)) ? "YES" : "NO") << endl;
    }
}
