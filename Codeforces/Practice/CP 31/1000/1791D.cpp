#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        string s;
        cin >> s;
        lli ans = 2;
        // Count Unique
        map<char,lli> a,b;
        for(char ch: s) b[ch]++;
        for(char ch: s){
            a[ch]++;
            if(b[ch] == 1) b.erase(ch);
            else b[ch]--;
            ans = (a.size() + b.size() > ans) ? a.size() + b.size() : ans;
        }
        cout << ans << endl;
        
    }
}
