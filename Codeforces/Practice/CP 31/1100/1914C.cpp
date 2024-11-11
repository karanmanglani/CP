#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli t;
    cin >> t;
    while(t--){
        lli n,k;
        cin >> n >> k;
        vector<lli> a(n),b(n);
        for(lli i = 0; i < n; i++) cin >> a[i];
        for(lli i = 0;i < n; i++) cin >> b[i];
        lli bm = 0 , ans = 0, temp = 0;
        for(lli i = 0;i<n and k > 0;i++){
            temp += a[i];
            k--;
            bm = max(bm,b[i]);
            lli sum = temp + bm*k;
            ans = max(sum,ans);
        }
        cout << ans << endl;
    }
}