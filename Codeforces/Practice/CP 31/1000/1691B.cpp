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
        vector<lli> s(n);
        map<lli,lli> cnt;
        for(lli i = 0;i < n;i++){
            cin >> s[i];
            cnt[s[i]]++;
        }
        bool pos = true;
        for(auto x : cnt){
            if(x.second < 2){
                pos = false;
                break;
            }
        }
        if(!pos){
            cout << -1 << endl;
            continue;
        }
        vector<lli> ans;
        lli i = 0;
        while(i < n){
            ans.push_back(i + cnt[s[i]] - 1);
            for(lli x = i; x < i + cnt[s[i]] - 1;x++) ans.push_back(x);
            i += cnt[s[i]];
        }
        
        for(auto x : ans){
            cout << x+1 << " ";
        }cout << endl;
    }
}
