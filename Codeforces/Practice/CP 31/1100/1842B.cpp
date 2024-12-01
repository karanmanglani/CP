#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isSafe(vector<lli> zpos, lli num){
    vector<lli> opos;
    lli cnt = 0;
    lli n = 64;
    while(n--){
        if(num & 1) opos.push_back(cnt);
        num >>= 1;
        cnt++;
    }
    for(auto i : opos){
        for(lli j = 0;j < zpos.size();j++){
            if(zpos[j] == i) return false;
        }
    }
    return true;
}

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,x;
	    cin >> n >> x;
	    vector<lli> a(n),b(n),c(n);
	    for(lli i = 0;i < n;i++) cin >> a[i];
	    for(lli i = 0;i < n;i++) cin >> b[i];
	    for(lli i = 0;i < n;i++) cin >> c[i];
	    
	    lli i = 0;
	    lli k = 0;
	    if(x == k) {
	        cout << "Yes" << endl;
	        continue;
	    }
	    vector<lli> zpos;
	    lli z = x;
	    lli cnt = 0;
	    lli num = 64;
	    while(num--){
	        if(!(z & 1)) zpos.push_back(cnt);
	        cnt++;
	        z >>= 1;
	    }
	    bool ans = false;
	    bool ai = true, bi = true, ci = true;
	    for(lli i = 0;i < n;i++){
	        if(ai and !isSafe(zpos,a[i])) ai = false;
	        if(bi and !isSafe(zpos,b[i])) bi = false;
	        if(ci and !isSafe(zpos,c[i])) ci = false;
	        
	        if(ai) k = k | a[i];
	        if(k == x) {cout << "Yes" << endl;ans = true;break;}
	        if(bi) k = k | b[i];
	        if(k == x) {cout << "Yes" << endl;ans = true;break;}
	        if(ci) k = k | c[i];
	        if(k == x) {cout << "Yes" << endl;ans = true;break;}
	        if(!ai and !bi and !ci) break;
	    }
	    if(!ans) cout << "No" << endl;
	}
    return 0;
}