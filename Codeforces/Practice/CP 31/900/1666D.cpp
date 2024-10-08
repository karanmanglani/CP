#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	while(n--){
	    string t,s;
	    unordered_map<char,bool> x,v;
	    cin >> s >> t;
	    if(s.size() < t.size()){
	        cout << "NO" << endl;
	        continue;
	    }
	    for(char i : t){
	        x[i] = true;
	    }
	    bool ans = true;
	    string k;
	    for(char i : s){
	        if(x[i]) k += i;
	    }
	    int i = k.size()-1,j = t.size()-1;
	    if(i < j) {
	        cout << "NO" << endl;
	        ans = false;
	        continue;
	    }
	    while(i >= 0 and j >= 0){
	        if(!ans) break;
	        if(i < j){
	            cout << "NO" << endl;
	            ans = false;
	            break;
	        }
	        if(k[i] == t[j] and !v[k[i]]){
	            i--;
	            j--;
	        }else if(k[i] == t[j] and v[k[i]]){
	            cout << "NO" << endl;
	            ans = false;
	            break;
	        }
	        else{
	            v[k[i]] = true;
	            i--;
	        }
	    }
	    if(j >= 0 and ans) {
	        cout << "NO" << endl;
	        ans = false;
	        continue;
	    }
	    if(ans) cout << "YES" << endl;
	}

}
