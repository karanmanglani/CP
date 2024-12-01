#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,c;
	    cin >> n >> c;
	    vector<lli> a(n);
	    for(lli i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    lli ans = 0;
	    lli s = 0, e = 1e9;
	    while(s <= e){
	        lli md = s + (e-s)/2;
	        lli sum = 0;
	        for(auto i : a){
	            lli e =  i + 2*md;
	            sum += e*e;
	            if(sum > c) break;
	        }
	        if(sum > c){
	            e = md - 1;
	        }else if(sum < c){
	            s = md + 1;
	        }else {
	            ans = md;
	            break;
	        }
	    }
	    cout << ans << endl;
	}
    return 0;
}