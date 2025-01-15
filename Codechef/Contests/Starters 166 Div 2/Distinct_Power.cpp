#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
	// your code goes here
    lli t;cin >> t;
    while(t--){
        lli n; cin >>n;
        vector<lli> a(n);
        lli ans = 1;
        for(lli i = 0;i < n;i++){
            cin >>a[i];
        }
        vector<lli> b = a;
        sort(b.begin(),b.end());
        vector<lli> rank(n);
        for(lli i = 0;i < n;i++){
            lli el = a[i];
            lli s = 0, e = n-1;
            lli p = -1;
            while(s <= e){
                lli md = s + (e-s)/2;
                if(b[md] == el) {p = md;break;}
                else if(b[md] > el) e = md - 1;
                else s = md + 1;
            }
            lli rnk = n - p;
            rank[i] = rnk;
        }
        for(lli i = 1;i < n;i++){
            if(abs(rank[i] - rank[i-1]) != 1) ans++;
        }
        if(n == 2) {cout << 1 << endl;continue;}
        else if(n == 3) {cout << min(ans,2LL) << endl;continue;}
        cout << ans << endl;
    }
}
