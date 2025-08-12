#include <bits/stdc++.h>
using namespace std;

// Problem: Compute range products of powers of two with modular arithmetic
// Approach: Use properties of powers of two and modular arithmetic to efficiently compute products

// Steps:
// 1. Identify the powers of two present in the binary representation of n.
// 2. Precompute the cumulative products of these powers.
// 3. For each query, compute the product of the specified range using precomputed values and modular inverses.
// 4. Use modular arithmetic to handle large numbers and avoid overflow.
// 5. The function uses a helper function for modular multiplication and another for computing modular inverses using Fermat's Little Theorem.
// 6. The maximum power of two considered is based on the constraints of the problem, ensuring efficient computation.

// Time Complexity: O(log n) for identifying powers of two, O(1) for each query after precomputation
// Space Complexity: O(log n) for storing powers and their inverses

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(),prices.end());
        int n = prices.size();
        int mini =0, maxi = 0;
        
        int j = n-1;
        
        // minimum calculation 
        for (int i = 0 ; i < n && i <= j ; i++){
            mini += prices[i];
            j -= k;
        }
        
        j=0;
        
        // maximum calculation 
        for (int i = n-1 ; i >= 0 && i >= j ; i--){
            maxi += prices[i];
            j += k;
        }
        
        return {mini,maxi};
    }
};