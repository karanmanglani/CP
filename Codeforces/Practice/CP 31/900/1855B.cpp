#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        
        lli n;
        cin >> n;
        lli ans = 1;
        for(lli i = 1;true;i++){
            if(n % i != 0) {
                ans = i - 1;
                break;
            }
        }
        cout << ans << endl;
        
    }
    return 0;
}