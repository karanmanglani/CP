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
        vector<lli> b = a;
        sort(b.begin(),b.end());
        map<lli,lli> ans;
        vector<lli> psum(n);
        lli temp = 0;
        for(lli i = 0;i < n;i++) {temp += b[i];psum[i] = temp;}
        ans[b[n-1]] = n-1;
        lli i = n-2;
        while(i >= 0){
            if(psum[i] >= b[i+1]) ans[b[i]] = ans[b[i+1]];
            else ans[b[i]] = i;
            i--;
        }
        
        for(lli x : a){
            cout << ans[x] << " ";
        }cout << endl;
    }
    return 0;
}
