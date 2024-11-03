#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli nCr(lli n, lli r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    if (r > n - r) r = n - r;

    lli result = 1;

    for (lli i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}