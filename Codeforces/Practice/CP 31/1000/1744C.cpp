#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;
        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        lli fg = 0,lg=n-1;
        while(s[fg] != 'g')fg++;
        if(c == 'r'){
            lli ri = 0;
            lli gi = fg;
            bool flag = true;
            lli ans = INT_MIN;
            for(lli i = 0;i < n;i++){
                if(flag){
                    if(s[i] == 'r'){
                        ri = i;
                        flag = !flag;
                    }
                }else {
                    if(s[i] == 'g'){
                        gi = i;
                        ans = max(ans,gi - ri);
                        flag = !flag;
                    }
                }
            }
            if(ri > gi){
                ans = max(ans , n - ri + fg);
            }
            cout << ans << endl;
        }else if(c == 'y'){
            lli yi = 0;
            lli gi = fg;
            bool flag = true;
            lli ans = INT_MIN;
            for(lli i = 0;i < n;i++){
                if(flag){
                    if(s[i] == 'y'){
                        yi = i;
                        flag = !flag;
                    }
                }else {
                    if(s[i] == 'g'){
                        gi = i;
                        ans = max(ans,gi - yi);
                        flag = !flag;
                    }
                }
            }
            if(yi > gi){
                ans = max(ans , n - yi + fg);
            }
            
            cout << ans << endl;
        }
        
    }
}