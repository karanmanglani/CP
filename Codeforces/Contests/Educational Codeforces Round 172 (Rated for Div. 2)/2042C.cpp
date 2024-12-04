#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<lli> diff(n);
        lli oc = 0, zc = 0;
        for (lli i = n - 1; i > 0; i--) {
            if (s[i] == '1') oc++;
            else zc++;
            diff[i] = oc - zc;
        }

        sort(diff.rbegin(), diff.rend());

        lli temp = 0, ans = -1;
        for (lli i = 0; i < n; i++) {
            temp += diff[i];
            if (temp >= k) {
                ans = i + 2; 
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}