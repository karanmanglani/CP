#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        lli b = 0,z = 0,t = k;
        lli i = 0, j = 0;
        while(t--){
            if(s[j++] == 'B')b++;
        }
        j--;
        lli c = max(k - b, z);
        while(j < n){
            if(s[i] == 'B')b--;
            i++;
            if(s[++j] == 'B')b++;
            lli d = max(k-b,z);
            c = min(c,d);
        }
        cout << c << endl;
        
    }
}
