#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<lli> b(n);
        bool ans = false;
        map<lli,bool> vis;
        for (lli i = 0; i < n; i++) {
            cin >> b[i];
            if(!vis[b[i]]){
                vis[b[i]] = true;
            }else ans = true;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}