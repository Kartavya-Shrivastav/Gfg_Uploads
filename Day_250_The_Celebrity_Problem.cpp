#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the celebrity in a party
    // Returns the index of celebrity if present, -1 if no celebrity exists
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // in[i] tracks the difference between people who know i and people i knows
        vector<int> in(n, 0);
        
        // Traverse the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // If i knows j, increment j's count and decrement i's count
                if(mat[i][j]) {
                    in[j]++; // j is known by one more person
                    in[i]--; // i knows one more person
                }
            }
        }
        
        // Check if any person has exactly n-1 incoming edges
        // (known by everyone except themselves)
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(in[i] == n-1) return i;
        }
        return -1; // No celebrity found
    }
};