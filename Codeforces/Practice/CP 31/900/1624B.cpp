#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    lli t;
    cin >> t;
    while(t--){
        lli a , b , c;
        cin >> a >> b >> c;
        if(2 * b == a + c){
            cout << "YES" << endl;
            continue;
        }
        // Change a 
        int d = c - b;
        int x = (b-d)/a;
        int z = a * x;
        if(x > 0 and 2*b == z + c){
            
            cout << "YES" << endl;
            continue;
        }
        
        // Change b 
        d = (c -a)/2;
        x = (a+d)/b;
        z = b *  x;
        if(x > 0 and 2*z == (a+c)){
            cout << "YES" << endl;
            continue;
        }
        
        // Change C
        d = b-a;
        x = (b + d)/c;
        z = c * x;
        if(x > 0 and 2*b == a+z){
            cout << "YES" << endl;
            continue;
        }
        
        // NOT Possible
        cout << "NO" << endl;
    }
    return 0;
}
