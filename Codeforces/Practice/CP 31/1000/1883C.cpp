#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n , k;
        cin >> n >> k;
        vector<lli> a(n);
        lli mn = k;
        bool flag = false;
        for(lli i = 0;i < n;i++){
            cin >> a[i];
            lli r = a[i] % k;
            if(r == 0) flag = true;
            r = k - r;
            // cout << r << " ";
            mn = (r < mn) ? r : mn;
           
        }
        // cout << endl;
        if(k == 4){
            lli cnt = 0;
            for(int i : a) if(i % 2 == 0)  cnt++;
            if(cnt > 2) mn = 0;
            else mn = (2 - cnt < mn) ? 2 - cnt : mn;
        }
        if(flag) cout << 0 << endl;
        else cout << mn << endl;
    }
}
