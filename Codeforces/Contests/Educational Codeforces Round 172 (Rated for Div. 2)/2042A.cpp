#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;



int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,k;
	    cin >> n >> k;
	    vector<lli> a(n);
	    lli sum = 0;
	    for(lli i = 0;i < n;i++){
	        cin >> a[i];
	    }
	    sort(a.rbegin(),a.rend());
	    for(auto i : a){
	        if(sum < k) sum += i;
	    }
	    lli ans = 0;
	    if(sum < k) ans = k - sum;
	    else if (sum > k) {
	       lli s = 0;
	       for(lli i = 0;i < n;i++) {
	           if(s + a[i] < k) s += a[i];
	           else break;
	       }
	       ans = k - s;
	    }
	    else ans = 0;
	    cout << ans << endl;
	}
    return 0;
}