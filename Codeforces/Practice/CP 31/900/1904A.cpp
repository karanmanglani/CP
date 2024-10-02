#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t;
    cin >> t;
    while(t--){
        lli a,b,xk,yk,xq,yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        set<pair<int,int>> pos;
        pos.insert({xk - a, yk - b});
        pos.insert({xk - a, yk + b});
        pos.insert({xk - b, yk - a});
        pos.insert({xk - b, yk + a});
        pos.insert({xk + a, yk - b});
        pos.insert({xk + a, yk + b});
        pos.insert({xk + b, yk - a});
        pos.insert({xk + b, yk + a});
        int ans = 0;
        
        for(pair<int,int> i: pos){
            if((abs(xq - i.first) == a and abs(yq - i.second) == b) or (abs(xq - i.first) == b and abs(yq - i.second) == a)) ans++;
        }
        cout << ans << endl;
        
    }
    return 0;
}