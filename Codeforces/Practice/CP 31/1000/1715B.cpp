#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli n , k , b ,s;
        cin >> n >> k >> b >> s;
        if(s < k * b){
            cout << -1 << endl;
            continue;
        }
        vector<lli> ans;
        lli toAdd = (b+1)*k - 1;
        if(toAdd > s){
            toAdd = s;
        }
        ans.push_back(toAdd);
        s -= toAdd;
        n--;
        while(n--){
            if(s >= k-1) {ans.push_back(k-1);s -= k-1;}
            else {ans.push_back(s); s = 0;}
        }
        if(s != 0){
            cout << -1 << endl;
            continue;
        }
        
        for(lli i : ans){
            cout << i << " ";
        }cout << endl;
    }
}
