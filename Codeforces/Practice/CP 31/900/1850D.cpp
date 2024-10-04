#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        
        lli n,k;
        cin >> n >> k;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        lli x = 0, i = 0 , j = 1,cnt =1;
        while(j < n){
            if(a[j] - a[i] <= k) {
                cnt++;
                i++;
                j++;
            }
            else{
                x = cnt > x ? cnt : x;
                cnt = 1;
                i = j;
                j++;
            }
            
        }
        x = cnt > x ? cnt : x;
        cout << n-x  << endl;
    }
    return 0;
}