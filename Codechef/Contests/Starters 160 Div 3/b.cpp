#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	lli t;
	cin >> t;
	while(t--){
	    lli n,m;
	    cin >> n >> m;
	    string s , t;
	    cin >> s >> t;
	    lli sa = 0,sb = 0, ta = 0,tb = 0;
	    for(char i : s){
	        if(i == 'a')sa++;
	        else sb++;
	    }
	    
	    for(char i : t){
	        if(i == 'a')ta++;
	        else tb++;
	    }
	    
	    lli sfa = -1,tfa = -1;
	    for(lli i = 0;i < n;i++) if(s[i] == 'a') {sfa = i; break;}
	    for(lli i = 0;i < m;i++) if(t[i] == 'a') {tfa = i; break;}
	    if(sfa != tfa){
	        cout << "NO" << endl;
	        continue;
	    }
	    
	    if(sa == ta){
	        if(sa == 0 ){
	            cout << ((sb == tb) ? "YES" : "NO") << endl;
	        }else{
	            cout << "YES" << endl;
	        }
	        
	    }else {
	        cout << "NO" << endl;
	    }
	}

}