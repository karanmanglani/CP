#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
#define endl '\n';
#define MOD 1000000007

lli nCr(lli n, lli r) { // TC -> O(r)
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

lli nPr(lli n, lli r) { // TC -> O(r)
    if (r > n) return 0;
    lli res = 1;
    for (lli i = 0; i < r; ++i) {
        res *= (n - i);
    }
    return res;
}

lli be(lli n, lli p) { // TC -> O(log(p))
    lli x = n;
    lli ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ans * x;
        }
        x *= x;
        p >>= 1;
    }
    return ans;
}

lli bem(lli n, lli p) { // TC -> O(log(p % (MOD - 1)))
    p = p % (MOD - 1);
    lli x = n;
    lli ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ((ans % MOD) * (x % MOD)) % MOD;
        }
        x = (x * x) % MOD;
        p >>= 1;
    }
    return ans;
}

pair<vector<bool>, pair<vector<lli> , vector<lli>>> primeArr(lli n) { // TC -> O(NloglogN)
    vector<bool> arr(n + 1, true);
    vector<lli> spf(n + 1, n);
    vector<lli> ptn;
    spf[1] = 1;
    arr[0] = false;
    arr[1] = false;
    for(lli i = 2; i * i <= n; i++) {
        if(arr[i]) {
            ptn.push_back(i);
            spf[i] = i;
            for(lli j = i * i; j <= n; j += i) {
                spf[j] = min(i, spf[j]);
                arr[j] = false;
            }
        }
    }
    return {arr, {spf,ptn}};
}

map<lli, lli> pfs(lli n, vector<lli>& spf) { // TC -> O(log n)
    map<lli, lli> m;
    while(n != 1) {
        m[spf[n]]++;
        n /= spf[n];
    }
    return m;
}

map<lli, lli> pf(lli n) { // TC -> O(sqrt(n) + log(n))
    map<lli, lli> m;
    for(lli i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if(n > 1) m[n]++;
    return m;
}

lli mi(lli x) {
    return bem(x, MOD - 2);
}

// **********************************************************************************************
// Author : Karan Manglani
// College: NIT Raipur
// Function Description
// be : Binary Exponentiation
// bem: Binary Exponentiation including Modulus
// primeArr: Returns {vector<bool> for seeing if a number is prime , {vector<lli> spf , vector<lli> ptn(prime till n)}}
// pfs: Prime Factorisation using SPF
// pf: Prime factorisation normally
// mi: return mod inverse
// **********************************************************************************************

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
    // lli t; cin >> t;
    lli t = 1;
    while(t--) {
        lli n,m;
        cin >> n >> m;
        vector<lli> a(n),b(m);
        auto x = primeArr(1e7);
        vector<lli> spf = x.second.first;
        map<lli,lli> num,den;
        for(auto &i : a){
            cin >> i;
            auto y = pfs(i,spf);
            for(auto j : y) num[j.first] += j.second;
        }

        for(auto &i : b){
            cin >> i;
            auto y = pfs(i,spf);
            for(auto j : y) den[j.first] += j.second;
        }
        vector<lli> c,d;
        for(auto &x : num){
            lli p = x.first;
            lli mn = min(x.second, den[p]);
            x.second -= mn;
            den[p] -= mn;
            if(x.second > 0){
                for(lli i = 0;i < x.second;i++) c.push_back(p);
            }
        }

        for(auto x : den){
            lli p = x.first,cnt = x.second;
            if(x.second > 0){
                for(lli i = 0;i < x.second;i++) d.push_back(p);
            }
        }
        if(c.size() == 0) c.push_back(1);
        if(d.size() == 0) d.push_back(1);
        cout << c.size() << " " << d.size() << endl;
        for(auto i : c) cout << i << " ";
        cout << endl;
        for(auto i : d) cout << i << " ";
        cout << endl;

    }
    return 0;
}