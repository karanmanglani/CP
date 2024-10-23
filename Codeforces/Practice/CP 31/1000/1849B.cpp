#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli t;
    cin >> t;
    while(t--) {
        int n;
        lli k;
        cin >> n >> k;
        vector<lli> a(n);
        vector<pair<lli, int>> v;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            lli x = a[i] % k;
            if(x == 0) x = k;
            v.push_back({x, i + 1});
        }

        sort(v.begin(), v.end(), [&](pair<lli, int> &x, pair<lli, int> &y) {
            if(x.first == y.first) return x.second < y.second;
            return x.first > y.first;
        });

        for(auto &p : v) {
            cout << p.second << " ";
        }
        cout << endl;
    }
}
