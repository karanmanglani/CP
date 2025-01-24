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

bool cmp(pair<lli,lli> x , pair<lli,lli> y) {return x.second > y.second;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    lli t; cin >> t;
    while (t--) {
        lli n; cin >> n;
        map<lli, vector<lli>> adj;
        map<lli,lli> deg;
        map<pair<lli,lli> , bool> mtrx;
        for (lli i = 0; i < n - 1; i++) {
            lli u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
            mtrx[{u,v}] = mtrx[{v,u}] = true;
        }
        if(n == 2){
            cout << 0 << endl;
            continue;
        }

        vector<pair<lli,lli>> sz;
        for(auto i : deg) sz.push_back(i);
        sort(sz.begin(),sz.end(), cmp);
        vector<lli> szs(2);
        szs[0] = sz[0].second;
        szs[1] = sz[1].second;
        vector<lli> pos;
        for(auto i : sz){
            if(i.second == szs[0] || i.second == szs[1]) pos.push_back(i.first);
        }
        lli ans = 1;
        for(lli i = 0;i < pos.size() - 1;i++){
            bool flag = false;
            for(lli j = i + 1;j < pos.size();j++){
                bool fnd = false;
                fnd = mtrx[{pos[i],pos[j]}];
                ans = (fnd) ? max(deg[pos[i]] + deg[pos[j]] - 2,ans) : max(ans,deg[pos[i]] + deg[pos[j]] - 1);
                if(!fnd) {flag = true; break;}
            }
            if(flag) break;
        }
        cout << ans << endl;
    }
    return 0;
}


