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
        for(lli i = 0;i < n;i++){
            lli z;
            cin >> z;
            a[i] *= z;
        }
        lli ans = 0;
        lli sum = 0;
        sort(a.rbegin(),a.rend());
        for(lli i : a){
            sum += i;
            ans++;
            if(sum >= x)break;
        }
        cout << ((sum < x) ? -1 : ans )<< endl;
    }
}
