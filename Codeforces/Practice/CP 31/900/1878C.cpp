#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;




int main(){
    int t;
    cin >> t;
    while(t--){
        lli n , k , x;
        cin >> n >> k >> x;
        if(k*(k+1)/2 > x){
            cout << "NO" << endl;
            continue;
        }
        lli mx = k*(2*n - k + 1)/2;
        if(x > mx){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}