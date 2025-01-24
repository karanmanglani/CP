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
    cin.tie(0) -> sync_with_stdio(0);
    // your code goes here
    lli t; cin >> t;
    //lli t = 1;
    while(t--) {
        lli n,l,r;cin >> n >> l >> r;
        l--;r--;
        vector<lli> a(n);for(auto &i: a) cin >>i ;
        vector<lli> b,c,d,e;
        lli ans = 0;
        for(lli i = 0;i < l;i++)b.push_back(a[i]);
        for(lli i = l;i <= r;i++)c.push_back(a[i]);
        for(lli i = r+1;i < n;i++)d.push_back(a[i]);
        for(auto i : c) ans += i;
        lli el = r - l + 1;
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());
        lli i = 0, j = 0;
        while(el--){
            if(i < b.size() and j < c.size()){
                if(b[i] < c[j]) e.push_back(b[i++]);
                else e.push_back(c[j++]);
            }else if (i < b.size()){
                e.push_back(b[i++]);
            }else if(j < c.size()){
                e.push_back(c[j++]);
            }
        }
        lli temp = 0;
        for(auto i : e){
            temp += i;
        }

        ans = min(ans,temp);
        temp = 0;
        e.clear();
        i = 0,j = 0,el = r-l+1;
        while(el--){
            if(i < c.size() and j < d.size()){
                if(c[i] < d[j]) e.push_back(c[i++]);
                else e.push_back(d[j++]);
            }else if (i < c.size()){
                e.push_back(c[i++]);
            }else if(j < d.size()){
                e.push_back(d[j++]);
            }
        }
        temp = 0;
        for(auto i : e){
            temp += i;
        }
        ans = min(ans,temp);
        cout << ans << endl;
    }
    return 0;
}