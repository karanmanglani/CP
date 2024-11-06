#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,x;
	    cin >> n >> x;
	    if(x & 1){
	        lli z = n/2;
	        z = n - z - 1;
	        cout << z << endl;
	    }else{
	        lli z = n/2 - 1;
	        cout << z << endl;
	    }
	}

}
