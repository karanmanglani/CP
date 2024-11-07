#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        lli a = 0,b = 0,sa = 0, sb = 0;
        lli c = min(n,m);
        lli i = 0;
        while(c--){
            if(s[i%k] == 'A'){
                sa += m + n - 1;
                sa -= 2 * a;
                sb -= 2*b;
                a++;
            }else{
                sb += m + n -1;
                sb -= 2 * b;
                sa -= 2 * a;
                b++;
            }
            i++;
        }
        if(sa == sb)cout << "Draw" << endl;
        else if(sa > sb) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}
