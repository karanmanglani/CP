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
	    vector<lli> p(n),a(n);
	    for(lli i = 0;i < n;i++){
	        cin >> p[i];
	    }
	    a = p;
	    sort(a.begin(),a.end());
	    if(a == p){
	        cout << n << endl;
	        continue;
	    }
	    lli ans = 0;
	    if(p[0] == 1 or p[n-1] == n){
	        ans = n - 1;
	    }else{
	       bool chk = false;
	       for(lli i = 0; i  < n ; i++){
	           if(p[i] == i+1) {chk = true; break;}
	       }
	       ans = (chk) ? n -1 :  n - 2; 
	    }
	    lli z = 0;
	    cout << ans << endl;
	}

}
