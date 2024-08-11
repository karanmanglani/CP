#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        bool closeRange = true;
        int n , d;
        cin >> n >> d;
        vector<int> a(n);
        for(int i = 0; i<n;i++) cin >> a[i];
        int ans = 0;
        
        for(int i : a){
            if(closeRange){
                if(i > d) {
                    ans++;
                    closeRange = !closeRange;
                }
            }else{
                if(i <= d){
                    ans++;
                    closeRange = !closeRange;
                }
            }
        }
        
        cout << ans << endl;
        
    }
}