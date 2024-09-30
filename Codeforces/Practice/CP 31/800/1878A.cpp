#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n,k;
	    cin >> n >> k;
	    vector<int> a(n);
	    bool found = false;
	    for(int i =0 ; i < n ;i++) {
	        cin >> a[i];
	        if(a[i] == k) found = true;
	    }
	    (found) ? cout << "yes" << endl : cout << "no" << endl;
	    
	}

}