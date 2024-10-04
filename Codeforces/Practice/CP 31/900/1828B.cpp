#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        vector<lli> p(n);
        for(lli i = 0;i < n;i++) cin >> p[i];
        vector<lli> diff;
        for(lli i = 0;i < n;i++){
            if(abs(p[i] - (i + 1)) > 0) diff.push_back(abs(p[i] - (i + 1)));
        }
        lli x = *min_element(diff.begin(),diff.end());
        for(lli i : diff){
            x = __gcd(i,x);
        }
        cout << x << endl;
    }
    return 0;
}