#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector<lli> a(n), b(n);
        for (lli i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (lli i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        unordered_map<lli, lli> maxCntA, maxCntB;
        
        lli count = 1;
        for (lli i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                count++;
            } else {
                maxCntA[a[i - 1]] = max(maxCntA[a[i - 1]], count);
                count = 1;
            }
        }
        maxCntA[a[n - 1]] = max(maxCntA[a[n - 1]], count);

        count = 1;
        for (lli i = 1; i < n; i++) {
            if (b[i] == b[i - 1]) {
                count++;
            } else {
                maxCntB[b[i - 1]] = max(maxCntB[b[i - 1]], count);
                count = 1;
            }
        }
        maxCntB[b[n - 1]] = max(maxCntB[b[n - 1]], count);

        lli ans = 0;
        for (auto &pair : maxCntA) {
            lli elem = pair.first;
            lli countA = pair.second;
            lli countB = maxCntB[elem];
            ans = max(ans, countA + countB);
        }
        
        for (auto &pair : maxCntB) {
            lli elem = pair.first;
            if (maxCntA.find(elem) == maxCntA.end()) {
                ans = max(ans, pair.second);
            }
        }

        cout << ans << endl;
    }
}
