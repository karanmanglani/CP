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
        lli neg = 0,x = 0,mNeg = INT_MAX;
        bool z = false;
        vector<lli> a(n*m);
        for(lli i = 0;i < n*m ;i++){
            cin >> a[i];
            if(a[i] == 0) z = true;
            if(a[i] < 0){
                neg++;
                a[i] = -a[i];
            }
            mNeg = min(mNeg,a[i]);
            x += a[i];
        }
        if(neg & 1){
            if(z) neg++;
        }
        
        cout << (neg & 1 ? x - 2*mNeg : x) << endl;
    }
    
}