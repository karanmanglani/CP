#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        int ans = INT_MIN;
        int mx = *max_element(a.begin(),a.end());
        int mn = *min_element(a.begin(),a.end());
        // Idx 0 fixed
        if(a[0] != mx){
            ans = max(ans,mx-a[0]);
        }
        // Idx n-1 fixed
        if(a[n-1] != mn){
            ans = max(ans,a[n-1]-mn);
        }
        
        // Now checking for cycle on whole length
        ans = max(ans,a[n-1]-a[0]);
        for(int i = 1;i < n;i++) ans = max(a[n-i-1]-a[n-i],ans);
        
        cout << ans << endl;
    }
    return 0;
}