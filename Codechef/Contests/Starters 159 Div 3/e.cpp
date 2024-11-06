#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        if(n & 1){
            lli ans = (n*n)/2;
            ans += 2;
            cout << ans << endl;
        }else{
            cout << 2 << endl;
        }
    }
}
