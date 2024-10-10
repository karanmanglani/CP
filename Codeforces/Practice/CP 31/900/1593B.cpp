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
        lli n;
        cin >> n;
        if(n % 25 == 0){
            cout << 0 << endl;
            continue;
        }
        string s = to_string(n);
        int x = s.size();
        string a = s,b =s;
        int ans = INT_MAX;
        int ctr = 0;
        // getting 00 in end or 50
        int i = x-1;
        while(a[i] != '0' and i > 0){
            a.erase(i--);
            ctr++;
        }
        while((a[i-1] != '0' and a[i-1] != '5') and i > 1){
            a.erase(i-1);
            i--;
            ctr++;
        }
        ans = min(ctr,ans);
        
        // getting last 25 or 75
        ctr = 0;
        i = x-1;
        while(b[i] != '5' and i > 0){
            b.erase(i--);
            ctr++;
        }
        while((b[i-1] != '2' and b[i-1] != '7') and i > 1){
            b.erase(i-1);
            i--;
            ctr++;
        }
        
        
        ans = min(ctr,ans);
        cout << ans << endl;
    }
    return 0;
}