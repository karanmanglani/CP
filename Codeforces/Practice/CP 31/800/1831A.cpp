#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        
        if(n & 1){
            int x = n/2;
            x++;
            x *= 2;
            for(int i : a){
                cout << x - i << " ";
                
            }cout << endl;
        }else{
           int x = n + 1;
           for(int i : a){
               cout << x - i << " ";
           }cout << endl;
        }
        
    }
    
    return 0;
}