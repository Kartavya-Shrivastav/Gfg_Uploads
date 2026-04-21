#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an integer n, return the number of binary strings of length n that do not contain consecutive 1's.
Approach: We can use dynamic programming to solve this problem. We can define two arrays, one for counting the number of binary strings of length i that end with 0 and another for counting the number of binary strings of length i that end with 1. The total number of binary strings of length i would be the sum of these two arrays. The base cases would be:

Steps:
1. For length 1, we have two binary strings: "0" and "1". So, count[1][0] = 1 and count[1][1] = 1.
2. For length 2, we can have "00", "01", and "10". So, count[2][0] = 2 and count[2][1] = 1.
3. For length i (i > 2), we can derive the counts as follows:   
    - count[i][0] = count[i-1][0] + count[i-1][1] (we can append '0' to any string of length i-1)
    - count[i][1] = count[i-1][0] (we can only append '1' to strings that end with '0' to avoid consecutive '1's)
    
4. Finally, the total number of binary strings of length n would be count[n][0] + count[n][1].

Time Complexity: O(n) - We need to compute the counts for all lengths from 1 to n.
Space Complexity: O(n) - We are using two arrays of size n to store the counts. However, we can optimize this to O(1) by only keeping track of the last two counts instead of the entire arrays.
*/

class Solution {
  public:
    int countStrings(int n) {
        int x=1, y=2;
        for(int i=2; i<=n; i++){
            int z=x+y;
            x=y;
            y=z;
        }
        return y;
    }
};