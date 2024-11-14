#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    string a,b,ans;
    cin >> a >> b;
    ans += a[0];
    lli i = 1;
    while(a[i] < b[0] and i < a.size()) ans += a[i++];
    ans += b[0];
    cout << ans << endl;
}