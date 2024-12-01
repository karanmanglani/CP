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
	    lli x = __gcd(a,b);
	    x = (a*b)/x;
	    cout << x << endl;
	}
}