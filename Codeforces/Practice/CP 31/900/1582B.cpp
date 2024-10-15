#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
   lli t;
   cin >> t;
   while(t--){
       lli n;
       cin >> n;
       vector<lli> a(n);
       lli o = 0,z=0;
       for(lli i = 0;i < n;i++) {
           cin >> a[i];
           if(a[i] == 0) z++;
           else if(a[i] == 1) o++;
       }
       lli ans = o * pow(2,z);
       
       
       cout << ans << endl;
   }
}