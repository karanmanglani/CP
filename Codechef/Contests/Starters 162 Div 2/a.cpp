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
	    vector<lli> a(n),b(n-1);
	    lli sum = 0;
	    for(lli i = 0;i < n-1;i++){
	        cin >> b[i];
	        sum += b[i];
	    }
	    sort(b.begin(),b.end());
	    
	    a[0] = 1;
	    
	    for(lli i = 1;i < n;i++){
	        a[i] = b[i-1] - a[i-1];
	    }
	    for(auto x : a) cout << x << " ";
	    cout << endl;
	}

}
