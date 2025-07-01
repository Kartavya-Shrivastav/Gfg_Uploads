#include <bits/stdc++.h>
using namespace std;

// Problem: Find the Nth natural number that does not contain the digit '9'.
// Approach: Use a recursive function to build the number by repeatedly dividing by 9 and appending the remainder.

// Steps:
// 1. If n is 0, return 0.
// 2. Calculate the remainder of n when divided by 9.
// 3. Recursively call the function with n divided by 9 to build the number
// 4. Append the remainder to the result.
// 5. Return the constructed number.

// Time Complexity: O(log n), where n is the input number.
// Space Complexity: O(log n) due to the recursive call stack.

class Solution {
  public:
    long long findNth(long long n) {
        int rem = n%9;
        if(n==0) return 0;
        long long ans = findNth(n/9);
        return ans*10+rem;
    }
};