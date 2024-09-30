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
	    vector<int> a(n);
	    for(int i = 0; i < n;i++){
	        cin >> a[i];
	    }
	    bool ans = true;
	    sort(a.begin(),a.end());
	    if(a[0] != a[n-1]){
	        for(int i = 1; i < n-1;i++){
	            if(a[i] != a[0] and a[i] != a[n-1]) {
	                ans = false;
	                break;
	            }
	        }
	        
	        if(abs(count(a.begin(),a.end(),a[0]) - count(a.begin(),a.end(),a[n-1])) > 1) ans = false;
	    } 
	    
	    
	    (ans)? cout << "yes" << endl : cout << "no" << endl;
	}

}