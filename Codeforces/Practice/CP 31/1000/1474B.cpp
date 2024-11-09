#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

bool isPrime(lli n){
    for(lli i = 2; i*i <= n;i++){
        if(n % i == 0) return false;
    }
    return true;
}

lli nextPrime(lli n){
    for(lli i = n;;i++){
        if(isPrime(i)) return i;
    }
}

int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli d;
        cin >> d;
        lli p = nextPrime(1+d);
        lli q = nextPrime(p+d);
        cout << min(p*p*p,p*q) << endl;
    }
    
}