#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli a,b;
        cin >> a >> b;
        lli rem = a % 4;
        lli x;
        if(rem == 1) x = a-1;
        else if( rem == 2) x = 1;
        else if( rem == 3) x = a;
        else if(rem == 0) x = 0;
        lli ans = a;
        if(x != b){
            if((x ^ b) != a) ans += 1;
            else ans += 2;
        }
        cout << ans << endl;
    }
}