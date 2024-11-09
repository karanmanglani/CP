#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli a,b;
        cin >> a >> b;
        lli ans = 1e9;
        
        for(lli x = b; x <= 6;x++){
            if(x == 1) continue;
            lli temp = x-b;
            lli ta = a;
            while(ta > 0) {
                ta /= x;
                temp++;
            }
            
            ans = min(temp,ans);
            
        }
        if(b > 6){
            ans = 0;
            while(a > 0){
                a /= b;
                ans++;
            }
        }
        
        cout << ans << endl;
    }
    
}