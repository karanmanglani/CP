#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i =0; i<n ; i++){
            cin >> a[i];
        }
        (a[0]==1) ? cout << "yes" <<endl : cout<<"no"<<endl;
        
    }
}