#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli largestOddFactorExcludingN(lli n) {
    while (n % 2 == 0) {
        n /= 2;
    }

    for (lli i = n / 2; i >= 1; i -= 2) {
        if (n % i == 0) {
            return i;
        }
    }
    
    return 1; 
}

int main() {
    lli n;
    cin >> n;
    cout << largestOddFactorExcludingN(n) << endl;
    return 0;
}
