#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n),b(n);
        int ans = 0;
        for(int i = 0; i<n;i++){
            cin >> a[i];
            b[i] = a[i] & 1;
        }
        
       int i = 0,j=1;
       int temp = 1;
       while(j < n){
           
           if(b[i] == b[j]){
               temp++;
           }else{
               if(temp > 1){
                   ans += temp - 1;
                   temp = 1;
               }
               i = j;
           }
           j++;
       }
       
      if(temp > 1){
          ans += temp - 1;
      }
       
       cout << ans << endl;
        
    }
    return 0;
}