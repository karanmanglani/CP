#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        string s;
        cin >> s;
        lli cnt = 1,x = 1,i = 0, j=1;
        while(j < n){
            if(s[i] == s[j]) x++;
            else{
                i = j;
                cnt = x > cnt ? x : cnt;
                x = 1;
            }
            j++;
        }
        cnt = x > cnt ? x : cnt;
        cout << cnt + 1 << endl;
    }
    return 0;
}