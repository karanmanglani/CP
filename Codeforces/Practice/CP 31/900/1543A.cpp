#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli t;
    cin >> t;
    while(t--){
        lli a , b;
        cin >> a >> b;
        if(a == b){
            cout <<  0 << " " << 0 << endl;
            continue;
        }
        cout << abs(b-a) << " ";
        lli x = abs(b-a);
        cout << min(max(a,b)%x,x - max(a,b)%x)<< endl;
        
    }
}