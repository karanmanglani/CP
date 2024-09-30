#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool found = false;
        int cnt = 0;
        for(int i = 0; i < n-2;i++){
            if(s[i] == '.' and s[i+1] == '.' and s[i+2] == '.'){
                found = true;
                break;
            }
        }
        for(int i = 0; i < n;i++) if(s[i] == '.') cnt++;
        (found == true) ? cout << 2 << endl : cout << cnt << endl;
        
    }
}