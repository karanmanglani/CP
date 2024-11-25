#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        string s;
        cin >> s;
        lli ans = 0;
        map<char,bool> vis;
        for(lli i = 0;i < n;i++){
            if(!vis[s[i]]){
                vis[s[i]] = true;
                ans += n-i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
