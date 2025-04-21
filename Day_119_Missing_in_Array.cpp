#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int xor1 =0, xor2 =0;
        for(int i=0;i<n;++i) xor1 = xor1^arr[i];
        
        n = n+1;
        if(n%4==0) return xor1^n;
        else if(n%4==1) return xor1^1;
        else if(n%4==2) return xor1^(n+1);
        else return xor1;
    }
};