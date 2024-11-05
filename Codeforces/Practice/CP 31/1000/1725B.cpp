#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    lli n,d;
    cin >> n >> d;
    vector<lli> p(n);
    for(lli i = 0;i < n;i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    lli i = 0,ans = 0,curr = 0,term = 0,j = n-1;
    bool flag = false;
    while(i <= j){
        if(curr <= d){
            if(!flag){
                term = p[j];
                flag = true;
                curr += term;
                j--;
            }else{
                curr += term;
                i++;
            }
        }else{
            
            flag = false;
            curr = 0;
            ans++;
        }
    }
    if(curr > d) ans++;
    cout << ans << endl;
}