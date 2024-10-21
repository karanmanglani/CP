#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    lli t;
    cin >> t;
    while(t--) {
        lli n;
        cin >> n;
        vector<lli> a(n);
        for(lli i = 0;i < n;i++) cin >> a[i];
        bool found = false;
        for(lli j = 1; j < n;j++){
            bool f1=false,f2 = false;
            lli i = 0;
            lli k = j + 1;
            for(;i < j;i++){
                if(a[i] < a[j]){
                    f1 = true;
                    break;
                }
            }
            if(f1){
                for(; k < n;k++){
                    if(a[k] < a[j]){
                        f2 = true;
                        break;
                    }
                }
            }
            
            if(f1 and f2){
                found = true;
                cout << "YES" << endl;
                cout << i+1 << " " << j+1 << " " << k+1 << " " << endl;
                break;
            }
        }
        if(!found){
            cout << "NO" << endl;
        }
    }
}
