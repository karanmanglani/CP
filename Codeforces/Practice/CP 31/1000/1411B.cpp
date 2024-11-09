#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isFair(lli n){
    lli t = n;
    while(t > 0){
        lli d = t% 10;
        t = t/10;
        if(d == 0) continue;
        if(n % d != 0) return false;
    }
    return true;
}

int main() {
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        lli t = 2520;
        while(t < n) t += t;
        for(lli i = n;i <= t ; i++){
            if(isFair(i)) {
                cout << i << endl;
                break;
            }
        }  
    }
    
}
