#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<lli> a(n),chk(n,0);
        chk[0] = 1;
        for(lli i = 0; i < n;i++){
            cin >> a[i];
            if(i == 0) continue;
            if((a[i-1] & 1) != (a[i] & 1)) chk[i] = 1;
        }
        lli i = 1,tmp = a[0];
        lli ans = a[0];
        while( i < n){
            ans = max(ans,a[i]);
            
            if(chk[i] == 1){
                if(tmp < 0) {ans =  max(tmp,ans);tmp = a[i];}
                else {ans = max(ans,tmp);tmp += a[i];}
                ans = max(tmp,ans);
                i++;
            }else{
                while(i < n and chk[i] != 1) {ans = max(a[i++],ans);}
                tmp = a[i-1];
                ans = max(tmp,ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
