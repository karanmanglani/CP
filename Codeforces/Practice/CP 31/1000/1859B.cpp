#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    lli t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;
       vector<vector<lli>> a(n);
       vector<int> min2;
       lli mn = INT_MAX;
       for(int i = 0;i < n;i++){
           lli min = INT_MAX;
           int m ;
           cin >> m;
           for(int j = 0; j < m ;j++) {
               lli k;
               cin >> k;
               a[i].push_back(k);
               min = (a[i][j] < min) ? a[i][j] : min;
           }
           // count min
           lli ct = 0;
           for(int x : a[i]) if(x == min) ct++;
           
           // finding 2nd min
           lli m2 = INT_MAX;
           if(ct == 1){
               for(int x : a[i]){
                   m2 = (x < m2 and x > min) ? x : m2;
               }
           }else m2 = min;
           
           min2.push_back(m2);
           mn = (min < mn) ? min : mn;
       }
       lli ans = mn;
       sort(min2.begin(),min2.end());
       for(int i = 1; i < min2.size() ; i++) ans += min2[i];
       cout << ans <<endl;
    }
}
