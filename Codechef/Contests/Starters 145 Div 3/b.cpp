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
	    lli sum = 0;
	    lli numZ = 0, nonZ = INT_MAX;
	    for(int i = 0; i< n;i++){
	        cin >> a[i];
	        sum += a[i];
	        if(a[i] == 0) numZ++;
	        else nonZ = a[i];
	    }
	    if(n * a[0] == sum){
	        cout << "yes" << endl;
	    }else if(nonZ * (n-numZ) == sum) cout << "yes" << endl;
	    else cout << "no" << endl;
	}

}