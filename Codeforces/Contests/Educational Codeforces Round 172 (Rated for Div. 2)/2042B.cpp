#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<lli> c(n);
        map<lli,lli> fc;
        for(lli i = 0;i <n;i++) {
            cin >> c[i];
            fc[c[i]]++;
        }
        lli o = 0;
        for(auto i : fc) if(i.second == 1) o++;
        lli no = fc.size() - o;
        lli a = (o & 1) ? o/2 + 1 : o/2, b = o - a;
        a *= 2;
        b *= 2;
        a += no;
        b += no;
        cout << a << endl;
    }
    return 0;
}