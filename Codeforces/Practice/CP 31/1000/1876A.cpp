#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n , p;
        cin >> n >> p;
        vector<lli> a(n),b(n);
        for(lli i = 0;i < n;i++) cin >> a[i];
        for(lli i = 0;i < n;i++) cin >> b[i];
        vector<pair<int,int>> c; // cost, no
        for(lli i = 0;i < n;i++){
            c.push_back({b[i],a[i]});
        }
        sort(c.begin(),c.end());
        lli left = n;
        lli i = 0;
        lli cost = 0;
       
        while(left and i < n){
            if(c[i].first < p){
                if(i == 0){
                    cost += p;
                    left--;
                }
                if(c[i].second > left){
                    cost += c[i].first * left;
                    left  = 0;
                }else{
                    cost += c[i].second * c[i].first;
                    left -= c[i].second;
                }
            }else{
                cost += left * p;
                left = 0;
            }
            i++;
        }
        cost += left * p;
        cout << cost << endl;
    }
}
