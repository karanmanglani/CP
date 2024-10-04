#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n,q;
        cin >> n >> q;
        vector<lli> a(n);
        unordered_map<lli,lli> x;
        lli sum = 0;
        for(lli i = 0;i < n;i++){
            cin >> a[i];
            sum += a[i];
            x[i+1] = sum;
        }
        while(q--){
            lli l,r,k;
            cin >> l >> r >>k;
            lli newSum = sum - (x[r] - x[l] )+ k*(r-l+1) -a[l-1];
            cout << (newSum & 1 ? "YES" : "NO") << endl;
        }
    }
    return 0;
}