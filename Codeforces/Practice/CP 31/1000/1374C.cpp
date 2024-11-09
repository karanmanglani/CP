#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        string s;
        cin >> s;
        lli a = 0,ans = 0;
        for(lli i = 0;i < n;i++){
            if(s[i] == '(')a++;
            else a--;
            if(a < 0){
                ans++;
                a = 0;
            }
        }
        cout << ans << endl;
    }
    
}
