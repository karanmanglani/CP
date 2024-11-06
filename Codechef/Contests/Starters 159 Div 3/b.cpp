#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n , x;
        cin >> n >> x;
        lli toWin = n/2 + 1;
        vector<lli> a(n),b(n),tw;
        for(lli i = 0;i < n;i++) cin >> a[i];
        for(lli i = 0;i < n;i++) cin >> b[i];
        for(lli i = 0;i < n;i++){
            if(a[i] > b[i]) toWin--;
            else {
                tw.push_back(b[i]-a[i] + 1);
            }
        }
        sort(tw.begin(),tw.end());
        lli j = 0;
        lli k = tw.size();
        while(toWin and j < k){
            if(x >= tw[j]){
                x -= tw[j++];
                toWin--;
            }else{
                break;
            }
        }
        cout << ((toWin > 0) ? "NO" : "YES" )<< endl;
    }
}
