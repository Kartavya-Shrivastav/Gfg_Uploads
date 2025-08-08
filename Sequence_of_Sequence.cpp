#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of sequences of length n that can be formed using numbers from 1 to m
// Approach: Use recursion to explore all possible sequences, ensuring that each number can be used multiple times.

// Steps:
// 1. Define a recursive function that takes the current index, maximum number (m), total length (n), and current sequence length (j).
// 2. If the current sequence length exceeds n, increment the count of valid sequences.
// 3. For each number from the current index, calculate the power of 2 based on the remaining length and recursively call the function
//    the next index.
// 4. Return the total count of valid sequences.

// Time Complexity: O(2^n), where n is the length of the sequence (due to recursive exploration)
// Space Complexity: O(n), for the recursion stack

class Solution {
  public:
    int maxcount = 0;
    void solve(int i, int m, int n, int j){
        if(j>n){
            maxcount++;
            return;
        }
        
        int power = pow(2,n-j);
        int start = i;
        while(start*power<=m){
            solve(start*2,m,n,j+1);
            start++;
        }
    }
    
    int numberSequence(int m, int n){
        int i = 1, j = 1;
        solve(i,m,n,j);
        return maxcount;
    }
};