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
	    lli sum = 0;
	    int temp = 0,cnt = 0,ans=0;
	    vector<int> a(n),zIndx;
	    map<int,pair<int,int>> x;
	    for(int i = 0; i < n;i++){
	        cin >> a[i];
	        temp += a[i];
	        sum += a[i];
	        if(a[i] == 0) {
	            zIndx.push_back(i);
	            x[i].first = temp; 
	            x[i].second = 0;
	            cnt++;
	        }
	    }
	    
	    for(int i : zIndx){
	        x[i].second = sum - x[i].first;
	    }
	    
	    
        for(int i : zIndx){
            if(x[i].first == x[i].second) ans += 2;
            else if(abs(x[i].first - x[i].second) == 1) ans += 1;
        }
	   cout << ans << endl;
	    
	    
	}

}