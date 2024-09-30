#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    int mn = INT_MAX;
	    bool flag = false;
	    for(int i = 0; i < n;i++){
	        cin >> a[i];
	    }
	    for(int i =1;i < n;i++){
	        if(a[i] - a[i-1] < 0) {
	            flag = true;
	            break;
	        }
	        mn = min(a[i] - a[i-1],mn);
	    }
	    if(flag){
	        cout << 0 << endl;
	        continue;
	    }
	    cout << mn/2 + 1 << endl;
	}

}