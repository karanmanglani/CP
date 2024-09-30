#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        int x;
        bool allSame = true;
        for(int i = 0; i<n;i++){
            cin >> a[i];
            if(i == 0) x = a[i];
            else if(x != a[i]) allSame = false;
        }
        
        if(allSame){
            cout << "NO" << endl;
            continue;
        }
        
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        if(a[0] == a[1]){
            int i = 2;
            while(a[0] == a[i]){
                i++;
            }
            swap(a[1],a[i]);
        }
        cout << "YES" << endl;
        for(int i : a) cout << i << " ";
        cout << endl;
        
    }
    return 0;
}