#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        vector<int> v(n);
        int c = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] == 0) c++;
        }
        
        if (c == 0) {
            cout << 1 << endl;
            continue;
        }
        
        if (c == n) {
            cout << 0 << endl;
            continue;
        }
        
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) l++;
            else break;
        }

        int r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 0) r++;
            else break;
        }

        if (l + r == c) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}
