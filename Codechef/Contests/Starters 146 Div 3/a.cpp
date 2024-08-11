#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int a , b ,c , m;
	    cin >> a >> b >> c >> m;
	    int x = abs(b-a) , y = abs(c - b) , z = abs(c - a);
	    if(m >= x or m >= y or m >= z) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}

}