#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        lli mx = 1;
        while(mx * 2 < n) mx *= 2;
        vector<lli> ans;
        for(lli i = mx - 1;i >= 0;i--)ans.push_back(i);
        for(lli i = mx;i < n;i++)ans.push_back(i);
        for(auto el : ans){
            cout << el << " ";
        }cout << endl;
    }
}
