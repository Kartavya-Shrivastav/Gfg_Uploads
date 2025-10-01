#include <bits/stdc++.h>
using namespace std;

// Problem: Generate all binary strings of length n
// Approach: We can use bit manipulation to generate all binary strings of length n.

// Steps:
// 1. Calculate the total number of binary strings of length n, which is 2^n.
// 2. Iterate from 0 to 2^n - 1 and for each number, convert it to a binary string of length n.
// 3. Store each binary string in a result vector.
// 4. Finally, return the result vector containing all binary strings.

// Time Complexity: O(n * 2^n)
// Space Complexity: O(2^n)

class Solution {
  public:
    vector<string> binstr(int n) {
        vector<string> result;
        int total = 1 << n;  // 2^n

        for (int i = 0; i < total; i++) {
            string s = bitset<20>(i).to_string(); // make 20-bit string
            result.push_back(s.substr(20 - n));   // take last n bits
        }
        return result;
    }
};