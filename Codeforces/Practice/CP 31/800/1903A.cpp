#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n , k;
	    cin >> n >> k;
	    vector<int>a(n);
	    for(int i = 0; i < n ;i++){
	        cin >> a[i];
	    }
	    vector<int> b = a;
	    sort(b.begin(),b.end());
	    if(b == a) {
	        cout << "yes" << endl;
	        continue;
	    }
	    
	    if(k == 1){
	        cout << "no" << endl;
	        continue;
	    }
	    
	    if(n == k){
	        reverse(b.begin() , b.end());
	        if(b==a){
	            cout << "yes" << endl;
	            continue;
	        }
	    }
	    
	    cout << "yes" << endl;
	    
	    
	}

}