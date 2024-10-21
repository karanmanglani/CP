#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;



int main() {
    lli t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        int x = 0,y = 0;
        for(int i = n-1;i >= 0;i--){
            (s[i] == '0') ? x++ : y++; 
        }
        int cnt = min(x,y);
        cout << ((cnt & 1) ? "DA" : "NET") << endl;
    }
}
