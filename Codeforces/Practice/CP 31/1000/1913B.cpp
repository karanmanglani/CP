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
        
        lli c0 = 0,c1 = 0;
        for(char ch : s){
            if(ch == '1') c1++;
            else c0++;
        }
        if(c0 < c1){
            int idx = 0,cnt = c0;
            while(cnt){
                if(s[idx++] == '1') cnt--;
            }
            while(s[idx] == '0') idx++;
            cout << n - idx << endl;
        }else if(c0 > c1){
            int idx = 0,cnt = c1;
            while(cnt){
                if(s[idx++] == '0') cnt--;
            }
            while(s[idx] == '1') idx++;
            cout << n - idx << endl;
        }else{
            cout << 0 << endl;
        }
    }
}
