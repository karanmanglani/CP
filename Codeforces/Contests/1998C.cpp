#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> temp(n);
        iota(temp.begin(), temp.end(), 0);
        
        sort(temp.begin(), temp.end(), [&](int i, int j) {
            return a[i] > a[j];
        });

        lli nd = ((n - 1) >> 1) + 1;
        lli low = 0, high = 1e10;
        
        while (low < high) {
            lli mid = (low + high + 1) >> 1;
            bool chk = 0;

            for (int i : temp) {
                if (b[i] == 1) {
                    if (a[i] + k >= mid) chk = 1;
                    lli x = mid - a[i] - k;
                    lli rem = nd;
                    for (int j : temp) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) rem--;
                    }
                    if (rem == 0) chk = 1;
                    break;
                }
            }

            for (int i : temp) {
                if (b[i] == 0) {
                    lli rem = nd;
                    lli sum = 0;
                    lli x = mid - a[i];
                    for (int j : temp) {
                        if (j == i) continue;
                        if (rem == 0) break;
                        if (a[j] >= x) rem--;
                        else if (b[j]) {
                            sum += x - a[j];
                            rem--;
                        }
                    }
                    if (rem == 0 && sum <= k) chk = 1;
                    break;
                }
            }
            
            if (chk) low = mid;
            else high = mid - 1;
        }
        cout << low << endl;
    }
    return 0;
}
