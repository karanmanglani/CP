#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        int mx = 0, mn = 0;
        vector<lli> a(n);
        unordered_map<int,int> y;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            mx += (a[i] % x == 0) ? a[i]/x : a[i]/x + 1;
            mn += a[i];
            y[a[i] % x]++;
        }
        mn = (mn%x == 0) ? mn/x : mx/x + 1;
        cout << mn << " " << mx<< endl;
    }
}
