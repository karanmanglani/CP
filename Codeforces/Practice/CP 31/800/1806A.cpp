#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a , b , c ,d;
        cin >> a >> b >> c >> d;
        if(b>d){
            cout << -1<< endl;
            continue;
        }
        
        int diff = d - b;
        a += diff;
        if(a<c){
            cout << -1<<endl;
            continue;
        }
        diff += a-c;
        cout << diff << endl;
    }
}