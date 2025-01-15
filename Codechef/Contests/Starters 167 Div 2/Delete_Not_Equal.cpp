#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n';

int main() {
	// your code goes here
	lli t;cin >> t;
	while(t--){
	    lli n;cin >> n;
	    string s;cin >> s;
	    lli a = 0, b= 0;
	    for(lli i = 0;i < n;i++){
	        if(s[i] == '0')a++;
	        else b++;
	    }
	    
	    if(a == 0 or b == 0) {
	        cout << n << endl;
	        continue;
	    }
	    
	    cout << 1 << endl;
	    
	}
	
	return 0;
}
