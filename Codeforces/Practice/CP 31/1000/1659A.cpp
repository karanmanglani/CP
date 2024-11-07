#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n,r,b;
        cin >> n >> r >> b;
        string ans;
        lli t = r/(b+1);
        lli w = r % (b+1);
        while(b--){
            for(lli i = 0;i < t;i++) ans += 'R';
            if(w){
                ans += 'R';
                w--;
            }
            ans += 'B';
        }
        for(lli i = 0;i < t;i++) ans += 'R';
        cout << ans << endl;
    }
}
