#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n-1);
	    lli x = 0;
	    for(int i =0 ; i < n-1 ;i++) {
	        cin >> a[i];
	        x += a[i];
	    }
	    
	    cout << 0 - x << endl;

	}

}