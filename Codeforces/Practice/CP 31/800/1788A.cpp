#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = 0;
        vector<int>a(n);
        
        for(int i = 0; i<n;i++){
            cin >> a[i];
            if(a[i] == 2) x++;
        }
        
        if(x & 1){
            cout << -1 << endl;
        }else{
            int z = x/2;
            int i = 0;
            while(z){
                if(a[i] == 2) z--;
                i++;
            }
            if(i == 0) cout << 1 << endl;
            else cout << i << endl;
        }
        
        
    }
}