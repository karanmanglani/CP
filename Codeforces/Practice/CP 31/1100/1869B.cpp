#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,k,a,b;
	    cin >> n >> k >> a >> b;
	    vector<pair<lli,lli>> pos(n);
	    for(lli i = 0;i < n;i++){
	        lli x,y;
	        cin >> x >> y;
	        pos[i] = {x,y};
	    }
	    lli mn = LLONG_MAX/2;
	    if(a <= k and b <= k){
	        cout << 0 << endl;
	        continue;
	    }else if(a > k and b <= k){
	        lli cost1 = llabs(pos[b-1].first - pos[a-1].first) + llabs(pos[a-1].second - pos[b-1].second);
	        mn = min(cost1,mn);
	        for(lli i = 0;i < k;i++){
	            lli cost = llabs(pos[a-1].first - pos[i].first) + llabs(pos[a-1].second - pos[i].second);
	            mn = min(mn,cost);
	        }
	    }else if(a <= k and b > k){
	        lli cost1 = llabs(pos[b-1].first - pos[a-1].first) + llabs(pos[a-1].second - pos[b-1].second);
	        mn = min(cost1,mn);
	        for(lli i = 0;i < k;i++){
	            lli cost = llabs(pos[b-1].first - pos[i].first) + llabs(pos[b-1].second - pos[i].second);
	            mn = min(mn,cost);
	        }
	    }else if(a > k and b > k){
	        lli cost1 = llabs(pos[b-1].first - pos[a-1].first) + llabs(pos[a-1].second - pos[b-1].second);
	        mn = min(cost1,mn);
	        lli cost2 = LLONG_MAX/2,cost3 = LLONG_MAX/2;
	        for(lli i = 0;i < k;i++){
	            lli cost = llabs(pos[a-1].first - pos[i].first) + llabs(pos[a-1].second - pos[i].second);
	            cost2 = min(cost2,cost);
	        }
	        for(lli i = 0;i < k;i++){
	            lli cost = llabs(pos[b-1].first - pos[i].first) + llabs(pos[b-1].second - pos[i].second);
	            cost3 = min(cost3,cost);
	        }
	        mn = min(mn,cost2 + cost3);
	    }
	    cout << mn << endl;
	}
    return 0;
}