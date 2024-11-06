#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli ld(lli n){
    lli ans = 1;
    for(lli i = 2; i * i <= n;i++){
        if(n % i == 0) return n/i;
    }
    return ans;
}

lli md(lli h){
    lli ans = 0;
    if(h == 1) return 0;
    while(h > 1){
        ans++;
        h = ld(h);
    }
    return ans;
}

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli h,k;
        cin >> h >> k;
        lli i = 1;
        while(i * 2 <= k) i *= 2;
        cout << md(h * i) << endl;
    }
}
