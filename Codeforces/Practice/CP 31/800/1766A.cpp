#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        int digits = 0;
        int x = n;
        while(x){
            x /= 10;
            digits++;
        }
        int ans  = (digits-1) * 9;
        ans += n/pow(10,digits-1);
        cout << ans << endl;
    }
    return 0;
}