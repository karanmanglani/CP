#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
#define endl '\n'
#define MOD 1000000007

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
    for(lli i = 2; i <= n; i++) {
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

pair<vector<lli>, vector<lli>> pcf(lli n){
    vector<lli> fct(n+1,1), ifct(n+1,1);
    for(lli i = 1;i <= n;i++){
        fct[i] = (fct[i-1]*i)%MOD;
    }
    ifct[n] = mi(fct[n]);
    for(lli i = n-1;i >= 1;i--){
        ifct[i] = (ifct[i+1]*(i+1))%MOD;
    }
    return {fct,ifct};
}

lli ncrf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if (r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[r]) % MOD;
    res = (res * ifct[n - r]) % MOD;
    return res;
}

lli nprf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if (r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[n - r]) % MOD;
    return res;
}

lli nCr(lli n, lli r) { // TC -> O(r)
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n - r) r = n - r;
    lli result = 1;
    for (lli i = 0; i < r; ++i) {
        result = (result * (n - i)) % MOD;
        result  = (result * mi(i + 1)) % MOD;
    }
    return result;
}

lli nPr(lli n, lli r) { // TC -> O(r)
    if (r > n) return 0;
    lli res = 1;
    for (lli i = 0; i < r; ++i) {
        res = (res * (n - i)) % MOD;
    }
    return res;
}

// **********************************************************************************************
// Classes for Data Structures
// 1. Disjoint Set
class DisjointSet {
    vector<lli> parent;
    vector<lli> rank;
    vector<lli> size;
public:
    DisjointSet(lli n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(lli i = 0;i <= n;i++){
            parent[i] = i;
        }
    }

    lli fup(lli node){
        if(parent[node] == node) return node;
        return parent[node] = fup(parent[node]);
    }

    void ubr(lli u, lli v){
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv){
            if(rank[pu] < rank[pv]){
                swap(pu, pv);
            }
            parent[pv] = pu;
            if(rank[pu] == rank[pv]){
                rank[pu]++;
            }
        }
    }

    void ubs(lli u, lli v){
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv){
            if(size[pu] < size[pv]){
                swap(pu, pv);
            }
            size[pu] += size[pv];
            size[pv] = 0;
            parent[pv] = pu;
        }
    }
};

// **********************************************************************************************

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
// pcf: returns {factorial array, inverse factorial array}
// ncrf: nCr using factorial array
// ncrf: nCr using factorial array
// DisjointSet: Class for Disjoint Set Data Structure
// **********************************************************************************************

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // your code goes here
    lli t; cin >> t;
    //lli t = 1;
    while(t--) {
        lli n,m;cin >> n >> m;
        vector<vector<lli>> arr(n, vector<lli>(m));
        for(lli i = 0;i < n;i++){
            for(lli j = 0;j < m;j++){
                cin >> arr[i][j];
            }
        }
        sort(arr.begin(), arr.end(), [&](vector<lli>& a, vector<lli>& b){
            lli s1 = 0, s2 = 0;
            lli k = 2*m;
            for(lli i = 0;i < m;i++){
                s1 += k * a[i];
                k--;
            }
            for(lli i = 0;i < m;i++){
                s1 += k * b[i];
                k--;
            }
            k = 2*m;
            for(lli i = 0;i < m;i++){
                s2 += k * b[i];
                k--;
            }
            for(lli i = 0;i < m;i++){
                s2 += k * a[i];
                k--;
            }
            return s1 > s2;
        });
        lli ans = 0;
        lli k = m*n;
        for(lli i = 0;i < n;i++){
            for(lli j = 0;j < m;j++){
                ans += k * arr[i][j];
                k--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}