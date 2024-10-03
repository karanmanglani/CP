#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        
        lli n;
        cin >> n;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++) cin >> a[i];
        lli x = 0;
        for(lli i: a) x ^= i;
        if(x == 0) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }else{
            if(n&1){
                cout << 4 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
                cout << 2 << " " << n << endl;
                cout << 2 << " " << n << endl;
            }else{
                cout << 2 << endl;
                cout << 1 << " " << n << endl;
                cout << 1 << " " << n << endl;
            }
            
        }
    }
    return 0;
}