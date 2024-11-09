#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    lli n;
    cin >> n;
    string s;
    cin >> s;
    lli ans;
    bool found = false;
    for(lli i = 1;i < n;i++){
        if(s[i] < s[i-1]){
            found = true;
            ans = i;
            break;
        }
    }
    if(!found){
        cout << "NO" << endl;
    }else{
        cout << "Yes" << endl;
        cout << ans << " " << ans + 1 << endl;
    }
}
