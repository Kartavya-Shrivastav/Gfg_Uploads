#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        unordered_map<int,unordered_map<int,int>>m;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<r+1;j++){
                if(r>n) {m[i][j]=0;continue;}
                if(j==0){m[i][j]=\1;continue;}
                m[i][j]=m[i-1][j-1]+m[i-1][j];
            }
        }
        return m[n][r];
    }
};