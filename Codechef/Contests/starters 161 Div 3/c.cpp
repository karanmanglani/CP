#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


bool chk(vector<lli> a, lli n , lli k,lli st){
    lli z = 0;
    lli mn = a[0] - k,mx = a[0] + k;
    for(lli i = 1;i < n;i++){
        if((a[i] <= mx  and a[i]  >= mn) or ((a[i] - k) <= mx and (a[i] + k) >= mn) or(a[i] + k <= mx and a[i] + k >= mn)){
            mn = max(mn,a[i] - k);
            mx = min(mx, a[i] + k);
        }else{
            z++;
            mn = a[i] - k;
            mx = a[i] + k;
        }
        if( z > st) return false;
    }
    return true;
}



int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,k;
	    cin >> n >> k;
	    vector<lli> a(n);
	    lli req = 0,  mx = 0, mn = LLONG_MAX;
	    for(lli i = 0; i< n;i++){
	        cin >> a[i];
	        if(i > 0 and a[i-1] != a[i]) req++;
	        mx = max(a[i],mx);
	        mn = min(a[i],mn);
	    }
	    if(req <= k) {
	        cout << 0 << endl;
	        continue;
	    }
	    
	    lli ans = mx - mn;
	    lli md;
	    lli s = 0, e = ans;
	    while(s <= e){
	        md = s + (e-s)/2;
	        if(chk(a,n,md,k)){
	            ans = md;
	            e = md - 1;
	        }else{
	            s = md + 1;
	        }
	    }
	    cout << ans << endl;
	    
	}

}
