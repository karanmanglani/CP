#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        
        lli a , b, n;
        cin >> a >> b >> n;
        vector<lli> t(n);
        for(int i = 0; i < n;i++){
            cin >> t[i];
        }
        lli ans = b;
        for(lli i : t){
            ans += (i < a-1) ? i : a-1;
        }
        cout << ans << endl;
    }
    return 0;
}