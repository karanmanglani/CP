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
        lli n,k; cin >> n>> k;
        vector<lli> a(n);for(auto &i : a) cin >> i;
        sort(a.rbegin(),a.rend());
        map<lli,vector<lli>> x;
        for(auto i : a){
            x[i%k].push_back(i);
        }
        lli ans = 0;
        // lli i = 1, j = k-1;
        vector<lli> vis(k,-1);
        // lli  l = 0, r = 0;
        // while(i < j){
        //     if(x[i].empty()) {i++; continue;}
        //     else if(x[j].empty()) {j--;continue;}
        //     if(l >= x[i].size()){
        //         i++;
        //         l = 0;
        //         continue;
        //     }else if(r >= x[j].size()){
        //         j--;
        //         r = 0;
        //         continue;
        //     }
        //     ans += (x[i][l] + x[j][r])/k;
        //     vis[i] = l++;
        //     vis[j] = r++;
        // }

        if(k & 1){
            for(lli i = 1;i <= k/2;i++){
                if(x[i].empty() || x[k-i].empty()) continue;
                lli l = 0, r = 0;
                while(l < x[i].size() && r < x[k-i].size()){
                    ans += (x[i][l] + x[k-i][r])/k;
                    vis[i] = l++;
                    vis[k-i] = r++;
                }
            }
        }else{
            for(lli i = 1;i < k/2;i++){
                if(x[i].empty() || x[k-i].empty()) continue;
                lli l = 0, r = 0;
                while(l < x[i].size() && r < x[k-i].size()){
                    ans += (x[i][l++] + x[k-i][r++])/k;
                    vis[i] = l++;
                    vis[k-i] = r++;
                }
            }
        }
        for(lli m = 1; m < k;m++){
            if(x[m].empty()) continue;
            if(vis[m] != x[m].size() - 1){
                lli idx = vis[m] + 1;
                for(;idx < x[m].size();idx++){
                    x[0].push_back(x[m][idx]);
                }
            }
        }

        if(!x[0].empty()){
            sort(x[0].rbegin(), x[0].rend());
            lli idx = 0;
            while(idx + 1 < x[0].size()){
                ans += (x[0][idx] + x[0][idx + 1])/k;
                idx += 2;
            }
        }

        cout << ans << endl;
    }
    return 0;
}