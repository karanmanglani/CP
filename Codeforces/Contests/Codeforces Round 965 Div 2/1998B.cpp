#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<int> p(n),q(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        for(int i = 0; i < n;i++){
            q[i] = p[(i+1)%n];
        }
        for(int i: q){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
