#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n;
	    cin >> n;
	    vector<lli> ans;
	    lli diff = 0;
	    for(lli i = 1; i <= n;i++){
	        ans.push_back(i + diff);
	        diff++;
	    }
	    for(auto i : ans) cout << i << " ";
	    cout << endl;
	}
    return 0;
}