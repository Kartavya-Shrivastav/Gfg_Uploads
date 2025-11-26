#include <bits/stdc++.h>
using namespace std;

// Problem: Given two integers l and r, return the bitwise AND of all integers in the inclusive range [l, r].
// Approach: We iterate through each bit position from 0 to 30 (assuming 32-bit integers).
// For each bit position, we check if the bit is set in l. If it is, we calculate the difference needed to reach the next higher bit.
// If the range size (r - l + 1) is less than or equal to this difference, it means that the bit remains set for all numbers in the range, so we set that bit in the result.

// Steps:
// 1. Initialize two variables: curr to keep track of the bits set so far, and res to store the final result.
// 2. Loop through each bit position from 0 to 30.  
// 3. For each bit position, check if the bit is set in l using bitwise AND.
// 4. If the bit is set, calculate the difference to the next higher bit.
// 5. Check if the size of the range (r - l + 1) is less than or equal to this difference.
// 6. If true, set that bit in the result using bitwise OR.

// Time Complexity: O(1) since we are iterating through a fixed number of bits (31).
// Space Complexity: O(1) as we are using a constant amount of extra space.


class Solution {
  public:
    int andInRange(int l, int r) {
        int curr = 0, res = 0;
        for(int i=0; i<31; ++i){
            if(l&(1<<i)){
                int diff = (1<<i) - curr;
                if(r-l+1 <= diff) res |= (1<<i);
            }
            
            curr |= (l&(1<<i));
        }
        
        return res;
    }
};
