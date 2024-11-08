#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool cmp(pair<lli,lli> &x , pair<lli,lli> &y){
    return x.second > y.second;
}


int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n;
        cin>> n;
        vector<pair<lli,lli>> freq,pos;
        vector<lli> a(n);
        vector<lli> ans;
        ans.push_back(0);
        for(lli i = 0;i < n;i++){
            cin >> a[i];
            freq.push_back({i+1,a[i]});
        }
        sort(freq.begin(),freq.end(),cmp);
        lli x = 1;
        for(lli i = 0;i < n;i++){
            lli p = x;
            x = (x > 0) ? -x : -x + 1;
            pos.push_back({freq[i].first,p});
        }
        sort(pos.begin(),pos.end());
        lli anss = 0;
        for(lli i = 0;i < n;i++){
            ans.push_back(pos[i].second);
            anss += 2 * abs(pos[i].second) * a[i];
        }
        cout << anss << endl;
        for(auto i : ans) cout << i << " ";
        cout << endl;
    }
}