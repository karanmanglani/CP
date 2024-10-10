#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> a(n);
        unordered_map<lli,lli> fc;
        for(lli i = 0;i < n;i++) {
            cin >> a[i];
            fc[a[i]]++;
        }
        lli maxi = INT_MIN;
        for(auto i : fc){
            maxi = (maxi < i.second) ? i.second : maxi;
        }
        lli rem = n - maxi;
        lli ans = rem;
        lli op = 0;
        while(rem > 0){
            rem -= maxi;
            maxi *= 2;
            op++;
        }
        cout << ans + op << endl;
    }
    return 0;
}
