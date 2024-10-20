#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n,x;
        cin >> n >> x;
        lli mx = 0, mn = 0;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++){
            cin >> a[i];
            mx += (a[i] % x == 0) ? a[i]/x : a[i]/x + 1;
            mn += a[i];
        }
        mn = (mn%x == 0) ? mn/x : mn/x + 1;
        cout << mn << " " << mx<< endl;
    }
}
