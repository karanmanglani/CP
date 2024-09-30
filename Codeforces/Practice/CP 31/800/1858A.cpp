#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int a , b , c;
	    cin >> a >> b >> c;
	    if(c & 1){
	        // Katie's turn 
	        cout << (!(b>a) ? "First" : "Second") << endl;
	    }else{
	        cout << ((a>b) ? "First" : "Second") << endl;
	    }

	}

}