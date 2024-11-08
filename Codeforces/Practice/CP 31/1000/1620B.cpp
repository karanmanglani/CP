#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
	// your code goes here
    lli t;
    cin >> t;
    while(t--){
        lli w,h,k;
        cin >> w >> h;
        
        lli maxiX = 0,maxiY = 0,maxi;
        lli mn,mx;
        // x,0
        cin >> k;
        for(lli i = 0 ; i< k;i++){
            lli tmp;
            cin >> tmp;
            if(i == 0) mn = tmp;
            else if(i == k-1) mx = tmp;
        }
        if(mx - mn >= maxiX){
            maxiX = mx - mn;
        }
        // x,h
        cin >> k;
        for(lli i = 0 ; i< k;i++){
            lli tmp;
            cin >> tmp;
            if(i == 0) mn = tmp;
            else if(i == k-1) mx = tmp;
        }
        if(mx - mn >= maxiX){
            maxiX = mx - mn;
        }
        maxi = maxiX * h;
        
        // 0,y
        cin >> k;
        for(lli i = 0 ; i< k;i++){
            lli tmp;
            cin >> tmp;
            if(i == 0) mn = tmp;
            else if(i == k-1) mx = tmp;
        }
        if(mx - mn >= maxiY){
            maxiY = mx - mn;
        }
        
        // w, y
        cin >> k;
        for(lli i = 0 ; i< k;i++){
            lli tmp;
            cin >> tmp;
            if(i == 0) mn = tmp;
            else if(i == k-1) mx = tmp;
        }
        if(mx - mn >= maxiY){
            maxiY = mx - mn;
        }
        maxi = (maxiY * w > maxi) ? (maxiY* w) : maxi;
        
        cout << maxi << endl;
    }
}