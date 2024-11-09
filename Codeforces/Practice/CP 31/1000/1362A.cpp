#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli t;
    cin >> t;
    while(t--){
        lli a , b;
        cin >> a >> b;
        lli m = a,n = b,mc = 0,nc = 0;
        while(!(m&1)){
            m /= 2;
            mc++;
        }
        
        while(!(n&1)){
            n /= 2;
            nc++;
        }
        
        if(m != n){
            cout << -1 << endl;
        }else{
            if(mc == nc) cout << 0 << endl;
            else{
                lli diff = abs(nc-mc);
                lli req = (diff)/3;
                if(diff%3 != 0) req++;
                cout << req << endl;
            }
        }
    }
    
}
