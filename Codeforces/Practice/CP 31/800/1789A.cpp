#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = 1;
        bool flag = false;
        vector<int>a(n);
        for(int i = 0; i<n;i++){
            cin >> a[i];
        }
        for(int i = 0; i < n;i++){
            for(int j = i;j < n;j++){
                if(__gcd(a[i],a[j]) <= 2){
                    flag = true;
                    break;
                }
            }
        }
        cout << ((flag == true)? "YES":"NO")<<endl;
        
    }
}