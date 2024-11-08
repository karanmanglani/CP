#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        lli m = a.size(),n = b.size();
        lli ans = m + n;
        for(lli i = 0;i < m;i++){
            for(lli j = 1; j <= m-i;j++){
                string sub = a.substr(i,j);
                if(b.find(sub) != string::npos){
                    lli ops = n - j + m - j;
                    ans = min(ans,ops);
                }
            }
        }
        cout << ans << endl;
    }
}