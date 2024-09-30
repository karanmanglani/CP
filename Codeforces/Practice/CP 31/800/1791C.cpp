#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0, j = n-1,x = n;
        while(j>i){
            if(s[i] != s[j]){
                x -= 2;
                i++;
                j--;
            }else break;
        }
        cout << x << endl;
    }
}