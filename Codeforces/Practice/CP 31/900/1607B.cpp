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
        lli x,n;
        cin >> x >> n;
        if(x % 2 == 0){
            int rem = n % 4;
            if(rem == 0){
                cout << x << endl;
                continue;
            }else if(rem == 1){
                cout << x - n << endl;
                continue;
            }else if(rem == 2){
                cout << x + 1 << endl;
                continue;
            }else if(rem == 3){
                cout << n + x + 1 << endl;
                continue;
            }
        }else{
            int rem = n % 4;
            if(rem == 0){
                cout << x << endl;
                continue;
            }else if(rem == 1){
                cout << n + x << endl;
                continue;
            }else if(rem == 2){
                cout << x - 1 << endl;
                continue;
            }else if(rem == 3){
                cout << x - n - 1 << endl;
                continue;
            }
        }
        
    }
    return 0;
}
