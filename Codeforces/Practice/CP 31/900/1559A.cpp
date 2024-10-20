#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> a(n);
        cin >> a[0];
        lli ans = a[0];
        for(lli i = 1;i<n;i++){
            cin >> a[i];
            ans &= a[i];
        }
        cout << ans << endl;
    }
}