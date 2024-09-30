#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    vector<vector<char>> s(10,vector<char>(10));
	    vector<pair<int,int>> pos;
	    for(int i =0; i<10;i++){
	        for(int j = 0; j < 10; j++){
	            cin >> s[i][j];
	            if(s[i][j] == 'X') pos.push_back({i+1,j+1});
	        }
	    }
	    int score = 0;
	    for(pair<int,int> p : pos ){
	        int x = p.first, y = p.second;
	        for(int i = 0; i<5 ; i++){
	            if(x == (i+1) or x == (10-i) or y == (i+1) or y == (10-i)) {
	                score += i+1;
	                break;
	            }
	        }
	    }
	    
	    cout << score << endl;

	}

}