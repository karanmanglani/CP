#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n,k;
        cin >> n>>k;
        lli mn= 10 * n, mx = 12 * n;
        if(k >= mn and k <= mx) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}