#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n;
        cin >> n;
        if(n == 1) { 
            cout << 1 << endl; 
            continue; 
        }
        else if(n == 2) { 
            cout << 1 << " " << 2 << endl; 
            continue; 
        }
        if(n % 2 == 1) {
            bool chk = false;
            for(lli i = 1, j = n; i <= (n / 2) + 1;) {
                if(chk == false) { 
                    cout << i << " "; 
                    chk = true; 
                    i++;
                } else { 
                    cout << j << " "; 
                    chk = false; 
                    j--;
                }
            }
        } else {
            bool chk = false;
            for(lli i = 1, j = n; i <= (n / 2); i++, j--) {
                cout << i << " " << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}