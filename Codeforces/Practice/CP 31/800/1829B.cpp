#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        
        int mx = 0,ans = 0;
        int i = 0,j=0;
        while(a[i] != 0 and i < n){
            i++;
            j++;
        }
        // if(i != n) mx = 1;
        
        while( j < n){
            if(a[j] == 0){mx++;j++;}
            else{
                i = j;
                ans = max(mx, ans);
                mx = 0;
                while(a[i] != 0 and i < n){
                    i++;
                }
                j = i;
            }
        }
        
        ans = max(mx , ans);
        cout << ans << endl;
        
        
    }
    
    return 0;
}