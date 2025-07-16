#include <bits/stdc++.h>
using namespace std;

// Problem: Count numbers with exactly nine divisors
// Approach: Check each perfect square up to n for its divisor count

// Steps:
// 1. Iterate through all integers i starting from 1 up to the square root of n.
// 2. For each i, calculate i*i and check how many divisors it has.
// 3. Count the divisors of i*i by iterating through all integers j from 1 to the square root of i*i.
// 4. If the count of divisors equals 9, increment the answer.
// 5. Return the total count of such numbers.

// Time Complexity: O(sqrt(n) * sqrt(n)) where n is the input number
// Space Complexity: O(1) since we are using a constant amount of space.

class Solution {
  public:
    int countNumbers(int n) {
        int ans = 0;
        for(int i=1;i*i<=n;i++){
            int ct = 0;
            for(int j=1;j*j<=i*i;j++){
                if((i*i)%j == 0){
                    ct++;
                    if(ct > 5)break;
                }
            }
            if(ct == 5){
                ans++;
            }
        }
        return ans;
    }
};