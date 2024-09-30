#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    string x , s;
	    cin >> n >> m;
	    cin >> x >> s;
	    int ans = 0;
	    
	    while(n < m){
	        ans++;
	        x += x;
	        n += n;
	    }
	    
	    if(n == m){
	        if(x.find(s) != string::npos){
	            cout << ans << endl;
	            continue;
	        }else{
	            x += x;
	            ans++;
	        }
	    }
	    
        if(x.find(s) != string::npos) {cout << ans << endl;continue;}
        else{
            x += x;
            ans++;
            (x.find(s) != string::npos) ? cout << ans << endl : cout << -1 << endl;
        }

	}

}