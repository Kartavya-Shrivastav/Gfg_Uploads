#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an integer n, return all the gray code sequences of length n.
Approach: We can generate the gray code sequences iteratively. We start with the base case for n=1, which is ["0", "1"]. For each subsequent value of n, we take the existing sequences and create new ones by prefixing '0' to the existing sequences and '1' to the reversed existing sequences. This way, we ensure that only one bit changes between consecutive codes.

Steps:
1. Initialize the answer vector with the base case for n=1: ["0", "1"].
2. For each value of i from 2 to n:
    a. Store the current size of the answer vector.
    b. Iterate through the existing codes in reverse order and create new codes by prefixing '1' to them, while also updating the existing codes by prefixing '0'.
    c. Append the new codes to the answer vector.
3. Return the final answer vector.

Time Complexity: O(2^n) since we generate 2^n codes.
Space Complexity: O(2^n) for storing the generated codes.
*/

class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> ans = {"0", "1"};
        
        for (int i = 2; i <= n; i++) {
            int size = ans.size();
            
            for (int j = size-1; j >= 0; j--) {
                ans.push_back('1'+ans[j]);
                ans[j] = '0'+ans[j];
                
            }
        }
        
        return ans;
    }
};