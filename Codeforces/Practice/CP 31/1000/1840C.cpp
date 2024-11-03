#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n,k,q;
        cin >> n >> k >> q;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++){
            cin >> a[i];
        }
        vector<lli> cnts;
        lli i = 0,cnt = 0;
        while(i<n){
            if(a[i] <= q){
                cnt++;
            }else{
                if(cnt>=k)cnts.push_back(cnt);
                cnt = 0;
            }
            i++;
        }
        cnts.push_back(cnt);
        lli ans = 0;
        
        for(lli b : cnts){
            if(b >= k) ans += (b-k+1)*(b+1) - b*(b+1)/2 + k*(k-1)/2;
            // cout << a << " ";
        }
        // cout << endl;
        cout << ans << endl;
        
    }
}
