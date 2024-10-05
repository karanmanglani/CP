#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
            if(a[i] == 1) a[i]++;
        }
        
        for(int i = 1; i < n;i++){
            if(a[i] % a[i-1] == 0) a[i]++;
        }
        for(int i: a){
            cout << i << " ";
        }cout << endl;
    }
    return 0;
}