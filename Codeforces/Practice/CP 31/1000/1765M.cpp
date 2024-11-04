#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        lli a = 1;
        for(lli g = 2;g * g <= n;g++){
            if(n % g == 0){
                a = n/g;
                break;
            }
        }
        lli b = n - a;
        cout << a << " " << b << endl;
    }
}