#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n,x;
        cin >> n >> x;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++){
            cin >> a[i];
        }
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        lli mn = a[0] - x ,mx = a[0] + x;
        lli v = a[0] - x;
        lli ans = 0;
        lli i = 1;
        while(i < n){
            lli tmn = a[i] - x, tmx = a[i] + x;
            mn = max(mn,tmn);
            mx = min(mx, tmx);
            if(v < tmn){
                v = tmn;
                if(v > mx){
                    mn = tmn;
                    mx = tmx;
                    ans++;
                }
            }else if(v > tmx){
                ans++;
                mn = tmn;
                mx = tmx;
                v = tmn;
            }
            i++;
        }
        cout << ans << endl;
    }
}
