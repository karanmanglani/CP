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
	    vector<lli> a(n);
	    for(lli i = 0;i < n;i++){
	        cin >> a[i];
	    }
	    vector<lli> pSum(n);
	    pSum[0] = a[0];
	    for(lli i = 1;i <n;i++) pSum[i] = a[i] + pSum[i-1];
	    
	    vector<lli> f;
	    for(lli i = 1;i * i <= n;i++){
	        if(n % i == 0){
	            f.push_back(i);
	            f.push_back(n/i);
	        }
	    }
	    lli ans = 0;
	    for(lli x : f){
	        lli b = n/x;
	        vector<lli> mxv;
	        lli i = 0;
	        while(b--){
	            
	            lli mx = (i == 0) ? pSum[x-1] : pSum[i+x] - pSum[i];
	            mxv.push_back(mx);
	            if(i == 0) i = x-1;
	            else i += x;
	        }
	        
	        sort(mxv.begin(),mxv.end());
	        lli temp = mxv[mxv.size() - 1] - mxv[0];
	        ans = max(temp,ans);
	        temp = *max_element(a.begin(),a.end()) - *min_element(a.begin(),a.end());
	        ans = max(ans,temp);
	    }
	    cout << ans << endl;
	}

}
