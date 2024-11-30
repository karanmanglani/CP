#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,q;
	    cin >> n >> q;
	    vector<lli> a(n),x(q);
	    map<lli,lli> tp;
	    for(lli i = 1;i <= 30 ;i++) tp[i] = pow(2,i);
	    for(lli i = 0;i < n;i++) cin >> a[i];
	    lli fo = -1,lo = -1;
	    for(lli i = 0;i < q; i++ ) {cin >> x[i];}
	    vector<lli> xn;
	    map<lli,bool> vis;
	    for(lli i = 0;i < q;i++){
	        if(!vis[x[i]]) {
	            xn.push_back(x[i]);
	            vis[x[i]] = true;
	        }
	    }
	    q = xn.size();
	    for(lli i = 0;i < n;i++){
	        for(lli j = 0;j < q;j++){
	            if(a[i] % tp[xn[j]] == 0) a[i] += tp[xn[j]]/2;
	        }
	    }
	    for(auto i : a) cout << i << " ";
	    cout << endl;
	}

}
