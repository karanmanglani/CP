#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
//typedef __int128 badaint;
typedef long double ld;
#define endl '\n';
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

lli bemp(lli n, lli p, lli pr) { // TC -> O(log(p % (pr - 1)))
    p = p % (pr - 1);
    lli x = n;
    lli ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ((ans % pr) * (x % pr)) % pr;
        }
        x = (x * x) % pr;
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

lli mi(lli x) { // TC -> O(log(MOD))
    return bem(x, MOD - 2);
}

lli mip(lli x, lli pr) { // TC -> O(log(pr))
    return bemp(x, pr - 2, pr);
}

lli mod_mul(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;} // TC -> O(1)
lli mod_sub(lli a, lli b, lli m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;} // TC -> O(1)

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

struct Hashing{
    string s;
    int n;
    int primes;
    vector<lli> hashPrimes = {1000000009, 100000007};
    const lli base = 31;
    vector<vector<lli>> hashValues;
    vector<vector<lli>> powersOfBase;
    vector<vector<lli>> inversePowersOfBase;
    Hashing(string a){
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < hashPrimes.size(); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mip(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<lli> substringHash(int l, int r){
        vector<lli> hash(primes);
        for(int i = 0; i < primes; i++){
            lli val1 = hashValues[i][r];
            lli val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};

// **********************************************************************************************

// **********************************************************************************************
// Author : Karan Manglani
// College: NIT Raipur
// Function Description
// be : Binary Exponentiation
// bem: Binary Exponentiation including Modulus
// bemp: Binary Exponentiation including Modulus with prime number given in argument
// primeArr: Returns {vector<bool> for seeing if a number is prime , {vector<lli> spf , vector<lli> ptn(prime till n)}}
// pfs: Prime Factorisation using SPF
// pf: Prime factorisation normally
// mi: return mod inverse
// mip: returns mod inverse with prime number given in argument
// mod_mul and mod_sub: returns (a*b)%m and (a-b)%m respectively
// pcf: returns {factorial array, inverse factorial array}
// ncrf: nCr using factorial array
// nprf: nPr using factorial array
// DisjointSet: Class for Disjoint Set Data Structure
// Hashing: Struct used for string hashing
// **********************************************************************************************

int main(){
    cin.tie(0)->sync_with_stdio(0);
    lli t;cin>>t;
    while(t--){
        lli n;cin>>n;
        lli q;cin>>q;
        while(q--){
            string s;cin>>s;
            if(s=="->"){
                lli x,y;cin>>x>>y;
                lli a=1, b=be(2,2*n);
                lli diff=be(2,n);
                while(diff>1){
                    lli qs=(b-a+1)/4;
                    if(x<=diff/2 && y<=diff/2){
                        b=a+qs-1;
                    } else if(x>diff/2 && y>diff/2){
                        a=a+qs;
                        b=a+qs-1;
                        x-=diff/2;
                        y-=diff/2;
                    } else if(x>diff/2 && y<=diff/2){
                        a=a+2*qs;
                        b=a+qs-1;
                        x-=diff/2;
                    } else{
                        a=a+3*qs;
                        b=a+qs-1;
                        y-=diff/2;
                    }
                    diff/=2;
                }
                cout<<a<<endl;
            } else{
                lli d;cin>>d;
                lli xmn=1, xmx=be(2,n), ymn=1, ymx=be(2,n);
                lli total=be(2,2*n);
                lli diff=be(2,n);
                while(diff>1){
                    lli qs=total/4;
                    if(d<=qs){
                        xmx=xmn+diff/2-1;
                        ymx=ymn+diff/2-1;
                    } else if(d<=2*qs){
                        d-=qs;
                        xmn=xmn+diff/2;
                        ymn=ymn+diff/2;
                        xmx=xmn+diff/2-1;
                        ymx=ymn+diff/2-1;
                    } else if(d<=3*qs){
                        d-=2*qs;
                        xmn=xmn+diff/2;
                        xmx=xmn+diff/2-1;
                        ymx=ymn+diff/2-1;
                    } else{
                        d-=3*qs;
                        ymn=ymn+diff/2;
                        ymx=ymn+diff/2-1;
                        xmx=xmn+diff/2-1;
                    }
                    total/=4;
                    diff/=2;
                }
                cout<<xmn<<" "<<ymn<<endl;
            }
        }
    }
    return 0;
}