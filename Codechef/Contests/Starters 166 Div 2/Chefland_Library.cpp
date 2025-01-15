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
	    vector<lli> a(n);
	    map<lli,lli> mp;
	    for(lli i = 0;i < n;i++){
	        cin >> a[i];
	        if(i+1 > mp[a[i]]) mp[a[i]] = i + 1;
	    }
	    lli ans = 0;
	    for(auto i : mp) ans += i.second;
	    cout << ans << endl;
	}

}
