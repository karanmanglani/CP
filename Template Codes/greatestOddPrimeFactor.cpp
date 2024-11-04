#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli gopf(lli n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    
    lli largestOddPrime = 1;
    for (lli i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestOddPrime = i;
            n /= i;
        }
    }
    
    if (n > 2) {
        largestOddPrime = n;
    }
    
    return largestOddPrime;
}

int main() {
    lli n;
    cin >> n;
    cout << gopf(n) << endl;
    return 0;
}
