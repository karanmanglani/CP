#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        string binaryString;
        cin >> binaryString;
        vector<long long int> zeroCounts;
        long long int countOnes = 0;
        long long int countZeros = 0;
        vector<bool> binaryArr(n, false);
        for(long long int i = 0; i < n; i++) 
            if(binaryString[i] == '1') 
                binaryArr[i] = true; 

        long long int zeroSeqCount = 0;
        long long int oneSeqCount = 0;
        bool currentCheck = binaryArr[0];
        if(binaryArr[0] == true)
            countOnes++;
        else
            countZeros++;
        
        long long int seqCount = 0;
        for(long long int i = 0; i < n; i++)
        {
            if(binaryArr[i] == true)
                oneSeqCount++;
            else
                zeroSeqCount++;
            
            if(binaryArr[i] != currentCheck)
            {
                if(binaryArr[i] == true) {
                    countOnes++; 
                    currentCheck = binaryArr[i]; 
                    zeroCounts.push_back(seqCount); 
                    seqCount = 0;
                }
                else {
                    countZeros++; 
                    currentCheck = binaryArr[i];
                }
            }
            if(currentCheck == false) 
                seqCount++;
        }
        if(seqCount > 0) 
            zeroCounts.push_back(seqCount);
        
        if(countZeros < countOnes) {
            cout << 0 << endl; 
            continue;
        }
        else 
        {  
            long long int ans = 0;
            sort(zeroCounts.begin(), zeroCounts.end());
            long long int totalSeq = zeroCounts.size();
            long long int i = 0;
            if(n == 2 && (binaryArr[0] == false && binaryArr[1] == false)) {
                cout << 2 << endl; 
                continue;
            }
            if(n > 2 && ((binaryArr[0] == false && binaryArr[1] == false))) {
                ans++; countOnes++;
            }
            if(n > 2 && ((binaryArr[n-1] == false && binaryArr[n-2] == false))) {
                ans++; countOnes++;
            }
            while(countZeros >= countOnes && i < totalSeq)
            {
                if(zeroCounts[i] == 2) {
                    countOnes++; 
                    ans++;
                }
                else if(zeroCounts[i] < 2) {
                    ans++; 
                    countZeros--;
                }
                i++;
            }
            if(zeroSeqCount == 0) 
                cout << 0 << endl;
            else if(ans == 0) 
                cout << zeroSeqCount << endl;
            else 
                cout << min(ans, zeroSeqCount) << endl;
        }
    }
}