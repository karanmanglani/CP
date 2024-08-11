#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    lli x,y,k;
	    cin >>x >> y >> k;
	    if(k == 1){
	        cout << x << " " << y << endl;
	        continue;
	    }
	    vector<pair<lli,lli>> points;
	    if(k&1){
	        points.push_back({x,y});
	        k--;
	    }
	    for(lli i = 1;i <= k/2; i++){
	        points.push_back({x-i,y-i});
	        points.push_back({x+i,y+i});
	    }
	    
	    for(auto i : points){
	        cout << i.first << " " << i.second << endl;
	    }

	}

}