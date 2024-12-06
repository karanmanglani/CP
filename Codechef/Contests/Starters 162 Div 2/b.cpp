#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n, k;
        cin >> n >> k;
        vector<lli> a(n);
        if(k == 1 or n == 1 or (k == 2 and (n & 1))) {
            cout << -1 << endl;
            continue;
        }
        for(lli i = 0;i < n;i++)a[i] = i+1;
        lli i = 0;
        bool flag = false;
        while(i < n){
            swap(a[i],a[i+1]);
            i+=2;
            if(i == n-1) {flag = true;break;}
        }
        if(flag) swap(a[n-1],a[n-2]);
        for(auto x : a) cout << x << " ";
        cout << endl;
    }
    return 0;
}
