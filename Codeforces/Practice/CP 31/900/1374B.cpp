#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool helper(lli n, lli& ans){
    if(n == 1) return true;
    if(n % 3 != 0) return false;
    
    if(n % 6 == 0){
        ans++;
        return helper(n/6,ans);
    }else{
        ans++;
        return helper(n*2,ans);
    }
}

int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n;
        cin >> n;
        if(n == 1) cout << 0 << endl;
        else{
            lli ans = 0;
            cout << (helper(n,ans) ? ans : -1) << endl;
        }
    }
}
