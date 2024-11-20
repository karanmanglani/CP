#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,m;
	    cin >> n >> m;
	    vector<lli> a(n),b(m);
	    lli ans = 0;
	    map<lli,lli> fc;
	    for(lli i = 0;i < n;i++) {
	        cin >> a[i];
	        fc[i+1] = a[i];
	    }
	    for(lli i = 0;i < m;i++){
	        cin >> b[i];
	        if(fc[b[i]] > 0) fc[b[i]]--;
	        else ans++;
	    }
	    cout << ans << endl;
	}

}
