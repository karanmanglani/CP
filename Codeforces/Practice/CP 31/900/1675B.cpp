#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;

        int ans = 0;
        bool possible = true;

        for(int i = n - 1; i > 0; i--) {
            if(a[i] == 0 && a[i - 1] != 0) {
                possible = false;
                break;
            }
            while(a[i] <= a[i - 1]) {
                if(a[i - 1] == 0) {
                    possible = false;
                    break;
                }
                a[i - 1] /= 2;
                ans++;
            }
            if (!possible) break;
        }

        cout << (possible ? ans : -1) << '\n';
    }

    return 0;
}
