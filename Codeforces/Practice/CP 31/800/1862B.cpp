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
	    vector<int> a(n),b;
	    for(int i = 0; i<n;i++){
	        cin >> a[i];
	    }
	    b.push_back(a[0]);
	    for(int i = 1; i < n;i++){
	        if(a[i-1] > a[i]) b.push_back(1);
	        b.push_back(a[i]);
	    }
	    cout << b.size() << endl;
	    for(int i : b){
	        cout << i << " ";
	    }cout << endl;
	    

	}

}