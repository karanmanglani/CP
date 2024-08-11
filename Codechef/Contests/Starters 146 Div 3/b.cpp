#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    vector<int> s(16);
	    for(int i = 0; i < 16; i++){
	        cin >> s[i];
	    }
	    vector<int> b = s;
	    sort(b.begin(),b.end());
	    vector<int> ans;
	    unordered_map<int,int> score;
	    for(int i= 0;i<16;i++){
	        if(i == 0) score[b[i]] = 0;
	        if(i == 15) score[b[i]] = 4;
	        if(i == 1 or i == 2) score[b[i]] = 1;
	        if(i >= 3 and i <= 6) score[b[i]] = 2;
	        if(i >= 7 and i <= 14) score[b[i]] = 3;
	    }
	    
	    for(int i : s){
	        ans.push_back(score[i]);
	    }
	    
	    for(int i : ans){
	        cout << i << " ";
	    }
	    cout << endl;
	    
	}

}