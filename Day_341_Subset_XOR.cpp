#include <bits/stdc++.h>
using namespace std;

// Problem: Given an integer n, return a subset of the set {1, 2, ..., n} such that the XOR of all elements in the subset is 0.
// Approach: The XOR of the entire set {1, 2, ..., n} can be computed. If it is not zero, we can exclude one element to make the XOR zero.

// Steps:
// 1. Compute the XOR of all integers from 1 to n.
// 2. Determine which element needs to be excluded to make the XOR of the remaining elements zero.
// 3. Construct the subset by including all elements except the one identified in step 2.
// 4. Return the constructed subset.

// Time Complexity: O(n) where n is the input integer, as we need to iterate through the numbers from 1 to n.
// Space Complexity: O(n) for storing the resulting subset.

class Solution {
  public:
    vector<int> subsetXOR(int n) {
        int xr = 0;
        for(int i = 1; i <= n; i++)
        {
          xr ^= i;   
        }
        int req = 0;
        for(int i = 0; i < 30; i++)
        {
            if((xr&(1<<i)) != (n&(1<<i)))
            {
                req |= (1<<i);
            }
        }
        vector<int>ans;
        for(int i = 1; i <= n; i++)
        {
            if(i != req)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};