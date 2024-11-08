#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
    lli n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
    }else{
        n++;
        cout << (n&1 ? n : n/2) << endl;
    }
    
}