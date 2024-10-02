#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int odds(vector<int> arr){
    int cnt = 0;
    for(int i : arr) if(i&1) cnt++;
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        string s;
        cin >> s;
        unordered_map<char,int> fq;
        for(char i: s) fq[i]++;
        vector<int> fc;
        for(auto i: fq) fc.push_back(i.second);
        sort(fc.begin(),fc.end());
        int rem = odds(fc);
        bool ans = false;
        if(k >= rem) ans = true;
        else if(rem - k == 1) ans = true;
        
        cout << (ans ?"YES" : "NO") << endl;
    }
    return 0;
}