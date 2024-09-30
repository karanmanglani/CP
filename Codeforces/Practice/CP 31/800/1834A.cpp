#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int neg = 0,sum = 0;
        for(int i = 0;i < n;i++){
            cin >> a[i];
            if(a[i] < 0) neg++;
            sum += a[i];
        }
        sort(a.begin(),a.end());
        if(neg & 1){
            if( sum > 0){
                cout << 1 << endl;
                continue;
            }else{
                int steps = 0;
                int i = 0;
                while(sum < 0 or (neg&1)){
                    a[i] = -a[i];
                    sum += 2 * a[i];
                    neg++;
                    steps++;
                    i++;
                }
                cout << steps << endl;
                continue;
            }
        }else{
            if(sum > 0){
                cout << 0 << endl;
                continue;
            }else{
                int steps = 0;
                int i = 0;
                while(sum < 0 or (neg&1)){
                    a[i] = -a[i];
                    sum += 2 * a[i];
                    neg++;
                    steps++;
                    i++;
                }
                cout << steps << endl;
                continue;
            }
        }
    }
    
    return 0;
}