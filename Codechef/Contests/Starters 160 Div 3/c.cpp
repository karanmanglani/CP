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
	    vector<lli> b(n);
	    for(lli i = 0;i < n ;i++) cin >> b[i];
	    lli ans = 0;
	    if(b[n-1]){
	        if(b[0]){
	            ans += 3;
	        }else{
	            ans += 2;
	        }
	    }else{
	        ans += 3;
	    }
	    ans += (n-2)*2;
	    cout << ans << endl;
	}

}