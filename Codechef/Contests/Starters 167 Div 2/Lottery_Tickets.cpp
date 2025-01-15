#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n';

int main() {
	// your code goes here
	lli t;cin >> t;
	while(t--){
	    lli n;cin >> n;
	    vector<lli> a(n);for(auto &i: a) cin >> i;
	    if(n == 1){
	        lli ans = 1e6;
	        cout << ans << endl;
	        continue;
	    }
	    lli x = a[0];
	    sort(a.begin(),a.end());
	    lli ans = 0;
	    if(a[n-1] == x) {
	        lli y = x;
	        lli s = 0 , e = n-1;
	        while(s <= e){
	            lli md = s + (e-s)/2;
	            if(a[md] < a[n-1]) {
	                y = a[md];
	                s = md + 1;
	            }else e = md - 1;
	        }
	        
	        lli md = y +( (x - y)/2);
	        if(md == x) ans += 1;
	        else if(abs(md-x) > abs(md - y)){
	            ans += x - md;
	        }else ans +=(md != y) ? x+ 1 - md : 1;
	        
	        ans += 1e6 - a[n-1];
	    }else if(x == a[0]){
	        ans += x - 1;
	        lli z = 0;
	        lli s= 0, e = n-1;
	        while(s <= e){
                lli md = s + (e-s)/2;
                if(a[md] > x){
                    z = md;
                    e = md -1 ;
                }else s = md + 1;
	        }
	        lli md = x + (a[z] - x)/2;
	        if(x == md) ans += 1;
	        else if(abs(md - x) > abs(a[z] - md)) ans += md - x;
	        else ans +=(md != a[z]) ?  md - x + 1 : 1;
	    }else{
	        lli y , z,i = 0;
	        lli s = 0, e = n-1;
	        while(s <= e){
	            lli md = s + (e-s)/2;
	            if(a[md] == x) {
	                i = md;
	                break;
	            }else if(a[md] < x){
	                s = md + 1;
	            }else e = md - 1;
	        }
	        
	        s = 0; e = n-1;
	        y = i;
	        while(s <= e){
	            lli md = s + (e-s)/2;
	            if(a[md] < x){
	                y = md;
	                s = md + 1;
	            }else e = md - 1;
	        }
	        
	        z = i;
	        s= 0; e = n-1;
	        while(s <= e){
	            lli md = s + (e-s)/2;
	            if(a[md] > x){
	                z = md;
	                e = md -1 ;
	            }else s = md + 1;
	        }
	        
	        lli md = a[y] + (x - a[y])/2;
	        if(x == md) ans+= 1;
	        else if(abs(x - md) > abs(md - a[y])) ans += x - md;
	        else ans += (md != a[y]) ? x - md + 1 : 1;

	        md = x + (a[z] - x)/2;
	        if(x == md) ans += 1;
	        else if(abs(md - x) > abs(a[z] - md)) ans += md - x;
	        else ans +=(md != a[z]) ?  md - x + 1 : 1;
	        ans--;
	    }
	    cout << ans << endl;
	}
	
	return 0;
}
