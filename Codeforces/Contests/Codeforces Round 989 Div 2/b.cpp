#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,m,k;
	    string s;
	    cin >> n >> m >> k;
	    cin >> s;
	    lli i = 0;
	    lli ctr = 0;
	    lli ans = 0;
	    while(i < n){
	        if(s[i] == '0') ctr++;
	        else ctr = 0;
	        if(ctr >= m){
	            for(lli j = i;j < i + k and j < n;j++) s[j] = '1';
	            ctr = 0;
	            ans++;
	            i = i + k ;
	        }else{
	            i++;
	        }
	    }
	    cout << ans << endl;
	}
}