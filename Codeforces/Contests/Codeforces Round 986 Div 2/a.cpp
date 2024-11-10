#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--){
        lli n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        lli i = 0;
        vector<lli> c(2),d(2);
        d[0] = a;
        d[1] = b;
        c[0] = 0;
        c[1] = 0;
        lli mx = 1000;
        bool ans = false;
        if(a == b and a == 0){
            cout << "Yes" << endl;
            continue;
        }
        while(mx--){
            lli idx = i % (n);
            if(s[idx]== 'N'){
                c[1]++;
            }else if(s[idx] == 'S'){
                c[1]--;
            }else if(s[idx] == 'E'){
                c[0]++;
            }else{
                c[0]--;
            }
            if(d[0] == c[0] and d[1] == c[1]){
                cout << "yes" << endl;
                ans = true;
                break;
            }
            i++;
        }
        if(!ans){
            cout << "no" << endl;
        }
    }
}