#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t; cin >> t;
	while (t--) {
	    ll index = -1;
	    ll n; cin >> n;
	    vector<ll> a(n);
	    vector<ll> b(n);
	    for (int i = 0; i < n; i++) {
	        cin >> a[i];
	        cin >> b[i];
	    }
	    ll maxi = INT_MIN;
	    for (int i = 0; i < n; i++) {
	        if (a[i] > maxi) {
	            index = i;
	            maxi = a[i];
	        }
	    }
	    for (int i = 0; i < n; i++) {
	        if (b[i] > maxi) {
	            maxi = b[i];
	            index = i;
	        }
	    }
	    ll smax = INT_MIN;
	    for (int i = 0; i < n; i++) {
	        if (i != index) {
	            smax = max(smax, max(a[i], b[i]));
	        }
	    }
	    if (smax >= maxi) {
	        cout << "NO" << endl;
	    } else {
	        cout << "YES" << endl;
	    }
	}
}
