#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >>  n;
	    
	    vector<int> a(n);
	    int sum = 0;
	    for(int i = 0;i < n;i++){
	        cin >> a[i];
	        sum += a[i];
	    }
	    cout << ((sum & 1) ? "NO" : "YES") << endl;
	    
	}

}