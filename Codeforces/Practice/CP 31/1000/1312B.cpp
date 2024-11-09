#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for(lli i : a) cout << i << " ";
        cout << endl;
    }
    
}
