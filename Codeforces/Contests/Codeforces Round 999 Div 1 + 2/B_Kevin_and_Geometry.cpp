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
        lli n;cin >> n;
        map<lli,lli> fq;
        vector<lli> a(n);for(auto &i : a) {cin >>i;fq[i]++;}
        vector<lli> pos(4,-1);
        bool flag = false;
        for(auto i : fq){
            if(i.second >= 4) {
                pos[0] = pos[1] = pos[2] = pos[3] = i.first;
                flag = true;
            }
        }
        vector<lli> dbl;
        bool ans = false;
        if(!flag){
            lli idx = 0;
            for(auto i : fq){
                if(i.second >= 2 ){
                    dbl.push_back(i.first);
                }
            }
        }

        if(dbl.size() >= 2){
            pos[0] = pos[1] = dbl[0];
            pos[2] = pos[3] = dbl[1];
        }else if(dbl.size() == 1){
            vector<lli> nums;
            pos[0] = pos[1] = dbl[0];
            for(auto i : fq){
                if(i.second != 2) nums.push_back(i.first);
            }
            if(nums.size() < 2) break;
            sort(nums.begin(), nums.end());

            lli x = pos[0];
            lli l = 0;
            for(lli r = 1; r < nums.size(); r++){
                if(nums[r] < (nums[l] + 2 * x)){
                    pos[2] = nums[l];
                    pos[3] = nums[r];
                }
                l++;
            }
        }


        if(!flag and dbl.size() == 0 || (pos[0] == -1 || pos[1] == -1 || pos[2] == -1 || pos[3] == -1)){
            cout << -1 << endl;
            continue;
        }
        for(auto i : pos) cout << i << " ";
        cout << endl;
    }
    return 0;
}