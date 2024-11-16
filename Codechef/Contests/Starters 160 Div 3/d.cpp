#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool check(string s, lli st, lli e){
    while(st < e){
        if(s[st++] != s[e--])return false;
    }
    return true;
}

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        string s;
        cin >> s;
        if(n ==1){
            cout << 0 << endl;
            continue;
        }
        if(check(s,0,n-1)){
            cout << 0 << endl;
        }else {
            if(check(s,0,n-2) and check(s,1,n-1)) cout << -1 << endl;
            else cout << 1 << endl;
        }
    }
}