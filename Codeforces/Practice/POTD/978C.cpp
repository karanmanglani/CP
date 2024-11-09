#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli n,m;
    cin >> n >> m;
    vector<lli> a(n),b(m),pSum(n,0);
    for(lli i = 0;i < n;i++){
        cin >> a[i];
        if(i == 0) pSum[i] = a[i];
        else pSum[i] = pSum[i-1] + a[i];
    }
    for(lli i = 0;i < m;i++){
        cin >> b[i];
    }
    
    for(auto x : b){
        lli s = 0, e = n-1;
        while(s <= e){
            m = e - (e-s)/2;
            if(pSum[m] == x) break;
            else if(pSum[m] > x) e = m-1;
            else s = m+1;
        }
        
        if(x > pSum[m])m++;
        lli last = 0;
        if(m != 0) last = pSum[m-1];
        cout << m+1 << " " << x - last << endl;
        
    }
    return 0;
}
