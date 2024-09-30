#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i <n;i++){
            cin >> a[i];
        }
        int x = a[0];
        for(int i = 1;i <n;i++){
            x^=a[i];
        }
        for(int i = 0;i <n;i++){
            a[i]^=x;
        }
        int y = a[0];
        for(int i = 1;i<n;i++){
            y^=a[i];
        }
        if(y == 0)cout << x << endl;
        else cout << -1 << endl;
    }
}