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
        string s;
        cin >> s;
        int n = s.size();
        s[0] = (s[0] == s[n-1]) ? s[0] : s[n-1];
        cout << s << endl;
    }
    return 0;
}