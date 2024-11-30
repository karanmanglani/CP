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
	    vector<lli> a(n);
	    for(lli i = 0;i < n;i++) {
	        cin >> a[i];
	    }
	    
	    lli s = 0, e= INT_MAX;
	    lli ans = 0;
	    while(s <= e){
	        lli md = s + (e-s)/2;
	        lli temp = 0;
	        bool flag = true;
	        for(lli i = 0;i < n;i++){
	            if(a[i] < md) temp += md - a[i];
	            if(temp > x) {flag = false; break;}
	            
	        }
	        if(temp > x or !flag){
	            e = md - 1;
	        }else{
	            ans = md;
	            s = md + 1;
	        }
	    }
	    cout << ans << endl;
	}

}
