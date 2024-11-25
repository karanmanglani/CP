#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli x,m;
        cin >> x >> m;
        lli z = 1;
        lli cnt = 0;
        if(x == 1){
            cout << m << endl;
            continue;
        }
        while(z < m) z *= 2;
        lli fp = x;
        for(lli i = 2; i * i <= x;i++) if(x % i == 0) {fp = i; break;}
        bool fnd = false;
        lli s = 1, e = z/fp;
        while(s <= e){
            lli md = s + (e-s)/2;
            lli y = (fp * md) ^ fp;
            if(y > m) e = md - 1;
            else {cnt =(y != 0 and y != 1 and y != x) ? md : md-1;s= md + 1;}
        }
        cnt++;
        if(m >= x) cnt++;
        cout << cnt <<  endl;
    }
    return 0;
}
