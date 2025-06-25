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

// Kosaraju's Algorithm for Strongly Connected Components
tuple<vector<vector<lli>>,vector<vector<lli>>,vector<lli>> kosaraju(vector<vector<lli>>& adj){
    lli n = adj.size();
    vector<lli> order;
    vector<bool> vis(n,false);
    auto dfs = [&](lli node, auto&& self) -> void{
        vis[node] = true;
        for(lli child : adj[node]) {
            if(!vis[child]) {
                self(child, self);
            }
        }
        order.push_back(node);
    };  

    for(lli i = 0;i < n;i++){
        if(!vis[i]) {
            dfs(i, dfs);
        }
    }

    reverse(order.begin(), order.end());
    fill(vis.begin(), vis.end(), false);
    vector<vector<lli>> adjR(n);
    for(lli i = 0; i < n; i++) {
        for(lli child : adj[i]) {
            adjR[child].push_back(i);
        }
    }

    vector<vector<lli>> scc;
    auto dfsR = [&](lli node, auto&& self) -> void {
        vis[node] = true;
        scc.back().push_back(node);
        for(lli child : adjR[node]) {
            if(!vis[child]) {
                self(child, self);
            }
        }
    };

    vector<lli> roots(n);

    for(auto node : order){
        if(vis[node]) continue;
        scc.push_back({});
        dfsR(node, dfsR);
        for(lli v : scc.back()) {
            roots[v] = node; 
        }
    }

    vector<vector<lli>> condensedGraph(n);
    for(lli i = 0; i < n; i++) {
        for(lli child : adj[i]) {
            if(roots[i] != roots[child]) {
                condensedGraph[roots[i]].push_back(roots[child]);
            }
        }
    }

    tuple<vector<vector<lli>>, vector<vector<lli>>, vector<lli>> result;
    get<0>(result) = scc; // Strongly Connected Components
    get<1>(result) = condensedGraph; // Condensed Graph
    get<2>(result) = roots; // Roots of each node in the condensed graph
    return result;

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
    lli sz = 0;
    Trie() {
        trie.push_back(TrieNode());
        sz++;
    }

    void add(string &word) {
        lli curr = 0;
        for (char ch : word) {
            if (trie[curr].children[ch - 'a'] == -1) {
                trie.push_back(TrieNode());
                trie[curr].children[ch - 'a'] = sz;
                sz++;
            }
            curr = trie[curr].children[ch - 'a'];
            trie[curr].stringsGoingBelow++;
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
        for (char ch : word) {
            lli child = trie[curr].children[ch - 'a'];
            trie[child].stringsGoingBelow--;
            if (trie[child].stringsGoingBelow == 0) {
                trie[curr].children[ch - 'a'] = -1;
            }
            curr = child;
        }
        trie[curr].stringsEndingHere--;
    }
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
            lli child = trie[curr].children[bit];
            trie[child].sgd--;
            if (trie[child].sgd == 0) {
                trie[curr].children[bit] = -1;
            }
            curr = child;
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
// kosaraju: returns {scc, condensed graph, roots of each node in condensed graph}
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
    lli t; cin >> t;
    // lli t = 1;
    while(t--) {
        lli n;cin >> n;
        vector<vector<lli>> shirts(100);
        cin.ignore();

        for(lli i = 0;i < n;i++){
            string s;getline(cin,s);
            stringstream ss(s);
            lli x;
            while(ss >> x){
                shirts[x-1].push_back(i);
            }
        }
        vector<vector<lli>> dp(100 , vector<lli>(1 << n,-1));
        auto f = [&](lli shirt, lli mask, auto&& self) -> lli{
            if(shirt == 100){
                if(mask == (1 << n) - 1) return 1;
                return 0;
            }
            if(dp[shirt][mask] != -1) return dp[shirt][mask];
            dp[shirt][mask] = 0;
            // Not take this shirt
            dp[shirt][mask] += self(shirt + 1, mask, self);
            dp[shirt][mask] %= MOD;
            // Take this shirt
            for(auto i : shirts[shirt]){
                if((mask & (1 << i)) == 0){
                    dp[shirt][mask] += self(shirt + 1, mask | (1 << i), self);
                    dp[shirt][mask] %= MOD;
                }
            }
            return dp[shirt][mask];
        };

        cout << f(0,0,f) << endl;
    }
    return 0;
}