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

pair<vector<bool>, pair<vector<lli>, vector<lli>>> primeArr(lli n) { // TC -> O(NloglogN)
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
    return {arr, {spf, ptn}};
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

lli mod_mul(lli a, lli b, lli m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; } // TC -> O(1)
lli mod_sub(lli a, lli b, lli m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; } // TC -> O(1)

pair<vector<lli>, vector<lli>> pcf(lli n) {
    vector<lli> fct(n + 1, 1), ifct(n + 1, 1);
    for(lli i = 1; i <= n; i++) {
        fct[i] = (fct[i - 1] * i) % MOD;
    }
    ifct[n] = mi(fct[n]);
    for(lli i = n - 1; i >= 1; i--) {
        ifct[i] = (ifct[i + 1] * (i + 1)) % MOD;
    }
    return {fct, ifct};
}

lli ncrf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if(r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[r]) % MOD;
    res = (res * ifct[n - r]) % MOD;
    return res;
}

lli nprf(lli n, lli r, vector<lli>& fct, vector<lli>& ifct) { // TC -> O(1)
    if(r > n) return 0;
    lli res = fct[n];
    res = (res * ifct[n - r]) % MOD;
    return res;
}

lli nCr(lli n, lli r) { // TC -> O(r)
    if(r > n) return 0;
    if(r == 0 || r == n) return 1;
    if(r > n - r) r = n - r;
    lli result = 1;
    for(lli i = 0; i < r; ++i) {
        result = (result * (n - i)) % MOD;
        result  = (result * mi(i + 1)) % MOD;
    }
    return result;
}

lli nPr(lli n, lli r) { // TC -> O(r)
    if(r > n) return 0;
    lli res = 1;
    for(lli i = 0; i < r; ++i) {
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
    DisjointSet(lli n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(lli i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    lli fup(lli node) {
        if(parent[node] == node) return node;
        return parent[node] = fup(parent[node]);
    }

    void ubr(lli u, lli v) {
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv) {
            if(rank[pu] < rank[pv]) {
                swap(pu, pv);
            }
            parent[pv] = pu;
            if(rank[pu] == rank[pv]) {
                rank[pu]++;
            }
        }
    }

    void ubs(lli u, lli v) {
        lli pu = fup(u);
        lli pv = fup(v);
        if(pu != pv) {
            if(size[pu] < size[pv]) {
                swap(pu, pv);
            }
            size[pu] += size[pv];
            size[pv] = 0;
            parent[pv] = pu;
        }
    }
};


// 2. String Hashing
struct Hashing {
    string s;
    lli n;
    lli primes;
    vector<lli> hashPrimes = {1000000009, 100000007};
    const lli base = 31;
    vector<vector<lli>> hashValues;
    vector<vector<lli>> powersOfBase;
    vector<vector<lli>> inversePowersOfBase;
    Hashing(string a) {
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for(lli i = 0; i < hashPrimes.size(); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(lli j = 1; j <= n; j++) {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mip(powersOfBase[i][n], hashPrimes[i]);
            for(lli j = n - 1; j >= 0; j--) {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            }
        }
        for(lli i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for(lli j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<lli> substringHash(lli l, lli r) {
        vector<lli> hash(primes);
        for(lli i = 0; i < primes; i++) {
            lli val1 = hashValues[i][r];
            lli val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
    vector<lli> rotatedSubstringHash(lli shift, lli l, lli r) {
        lli nl = l + shift;
        lli nr = r + shift;
        vector<lli> ansHash(primes);
        if(nr >= n) {
            vector<lli> hash1 = substringHash(nl, n - 1);
            vector<lli> hash2 = substringHash(0, nr % n);
            for(lli i = 0; i < primes; i++) {
                ansHash[i] = (hash1[i] + (powersOfBase[i][n - nl] * hash2[i])) % hashPrimes[i];
            }
        } else {
            return substringHash(nl, nr);
        }
        return ansHash;
    }
    vector<vector<lli>> getPowersOfBase() {
        return powersOfBase;
    }
};

vector<lli> addStringToEndHash(string &a, vector<lli> &ha, string &b, vector<lli> &hb, vector<vector<lli>>& powersOfBase) {
    vector<lli> hashPrimes = {1000000009, 100000007};
    vector<lli> ansHash(ha.size());
    for(lli i = 0; i < ha.size(); i++) {
        ansHash[i] = (ha[i] + powersOfBase[i][a.length()] * hb[i]) % hashPrimes[i];
    }
    return ansHash;
}



// 3. Trie
const lli letters = 26;
struct TrieNode {
    vector<lli> children;
    lli stringsEndingHere;
    lli stringsGoingBelow;
    TrieNode() {
        children.resize(letters, -1);
        stringsEndingHere = 0;
        stringsGoingBelow = 0;
    }
};

struct Trie {
    vector<TrieNode> trie;
    map<lli,multiset<lli>> mp;
    lli sz = 0;
    Trie() {
        trie.push_back(TrieNode());
        sz++;
    }

    void add(string &word) {
        lli curr = 0;
        lli len = 0;
        for (char ch : word) {
            if (trie[curr].children[ch - 'a'] == -1) {
                trie.push_back(TrieNode());
                trie[curr].children[ch - 'a'] = sz;
                sz++;
            }
            curr = trie[curr].children[ch - 'a'];
            trie[curr].stringsGoingBelow++;
            len++;
            if (trie[curr].stringsGoingBelow > 1) {
                mp[len].erase(mp[len].find(trie[curr].stringsGoingBelow - 1));
            }
            mp[len].insert(trie[curr].stringsGoingBelow);
        }
        trie[curr].stringsEndingHere++;
    }

    bool search(const string &word) {
        lli curr = 0;
        for (char ch : word) {
            if (trie[curr].children[ch - 'a'] == -1) return false;
            curr = trie[curr].children[ch - 'a'];
        }
        return trie[curr].stringsEndingHere > 0;
    }

    void deleteWord(const string &word) {
        if (!search(word)) return;
        lli curr = 0;
        lli len = 0;
        for (char ch : word) {
            curr = trie[curr].children[ch - 'a'];
            len++;
            auto it = mp[len].find(trie[curr].stringsGoingBelow);
            if (it != mp[len].end()) mp[len].erase(it);
            trie[curr].stringsGoingBelow--;
            if (trie[curr].stringsGoingBelow > 0)
                mp[len].insert(trie[curr].stringsGoingBelow);
        }
        trie[curr].stringsEndingHere--;
    }

    lli ans(lli len) {if (mp[len].empty()) return 0;return *mp[len].rbegin();}
};

// 4. Binary Trie
struct BinaryTrieNode {
    vector<lli> children;
    lli seh, sgd;
    BinaryTrieNode() {
        children.resize(2, -1);
        seh = 0;
        sgd = 0;
    }
};

struct BinaryTrie {
    vector<BinaryTrieNode> trie;
    lli sz = 0;
    BinaryTrie() {
        trie.push_back(BinaryTrieNode());
        sz++;
    }

    void insert(lli x) {
        lli curr = 0;
        for (lli i = 63; i >= 0; i--) {
            lli bit = (x >> i) & 1;
            if (trie[curr].children[bit] == -1) {
                trie.push_back(BinaryTrieNode());
                trie[curr].children[bit] = sz++;
            }
            curr = trie[curr].children[bit];
            trie[curr].sgd++;
        }
        trie[curr].seh++;
    }

    bool search(lli x) {
        lli curr = 0;
        for (lli i = 63; i >= 0; i--) {
            lli bit = (x >> i) & 1;
            if (trie[curr].children[bit] == -1) return false;
            curr = trie[curr].children[bit];
        }
        return trie[curr].seh > 0;
    }

    void erase(lli x) {
        if (!search(x)) return;
        lli curr = 0;
        for (lli i = 63; i >= 0; i--) {
            lli bit = (x >> i) & 1;
            curr = trie[curr].children[bit];
            trie[curr].sgd--;
            if (trie[curr].sgd == 0) {
                trie[curr].children[bit] = -1;
                return;
            }
        }
        trie[curr].seh--;
    }

    lli mxXor(lli num) {
        lli curr = 0;
        lli ans = 0;
        for (lli i = 63; i >= 0; i--) {
            lli bit = (num >> i) & 1;
            lli opp = bit ^ 1;
            if (trie[curr].children[opp] != -1) {
                ans |= (1LL << i);
                curr = trie[curr].children[opp];
            } else {
                curr = trie[curr].children[bit];
            }
        }
        return ans;
    }
};

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
// nCr: combinations using mod inverse method
// nPr: permutations using mod inverse method
// DisjointSet: Class for Disjoint Set Data Structure
// Hashing: Struct used for string hashing
// addStringToEnd: concatenates string hashes
// TrieNode: Node of Trie
// Trie: Class for Trie Data Structure
// BinaryTrie: Class for Binary Trie Data Structure
// **********************************************************************************************

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    // your code goes here
    // lli t; cin >> t;
    lli t = 1;
    while(t--) {
        lli q;cin >> q;
        vector<pair<string,pair<string,string>>> s(q);
        vector<bool> flag(q,false);
        for(auto &i : s) {cin >> i.first >> i.second.first;if(i.first == "2") cin >> i.second.second;}
        Trie tr;
        for(auto i : s){
            if(i.first == "1"){
                string str = i.second.first;
                reverse(str.begin(), str.end());
                tr.add(str);
            }else if(i.first == "2"){
                lli k = stoll(i.second.first);
                lli len = stoll(i.second.second);
                cout << (tr.ans(len) >= k ? "YES" : "NO")  << endl;
            }else if(i.first == "3"){
                lli idx = stoll(i.second.first)-1;
                if(flag[idx]) continue;
                flag[idx] = true;
                string str = s[idx].second.first;
                reverse(str.begin(), str.end());
                tr.deleteWord(str);
            }
        }
    }
    return 0;
}