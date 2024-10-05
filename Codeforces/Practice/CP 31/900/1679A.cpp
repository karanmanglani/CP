#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    int t; cin >> t;
    while(t--){
        lli n;
        cin >> n;
        if(n & 1 or n < 4){
            cout << -1 << endl;
            continue;
        }
        lli mx,mn;
        if(n % 4 == 0){
            mx = n/4;
            if(n % 6 == 0){
                mn = n/6;
            }else{
                lli x = n/6;
                if(n % 6 == 2) mn = (x-1) + (n-6*(x-1))/4;
                if(n % 6 == 4) mn = (x) + (n-6*(x))/4;
            }
        }else if(n % 6 == 0){
            mn = n/6;
            if(n%4 == 0) mx = n/4;
            else mx = 1 + (n-6)/4;
        }else{
            if(n %6 == 2){
                mx = 1 + (n-6)/4;
                mn = 2 + (n-8)/6;
            }else{
                mn = n/6;
                mn++;
                mx = (n-6)/4;
                mx++;
            }
        }
        cout << mn << " " << mx << endl;
        
    }
    return 0;
}
