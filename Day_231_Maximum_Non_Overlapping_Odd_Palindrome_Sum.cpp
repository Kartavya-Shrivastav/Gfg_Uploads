#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum sum of lengths of two non-overlapping palindromic substrings
// Approach: Use Manacher's algorithm to find all palindromic substrings and then calculate the maximum sum of lengths of two non-overlapping palindromes

// Steps:
// 1. Use Manacher's algorithm to find the lengths of palindromes centered at each character in the string.
// 2. Create two arrays: one for the best palindrome ending at each index and another
//    for the best palindrome starting at each index.
// 3. Iterate through the string to fill these arrays with the maximum lengths of palindromes that end or start at each index.
// 4. Traverse the string to find the maximum sum of lengths of two non-overlapping palindromic substrings by combining the best
//    palindrome ending before an index with the best palindrome starting after that index.
// 5. Return the maximum sum found.

// Time Complexity: O(n), where n is the length of the string (due to linear traversal and Manacher's algorithm)
// Space Complexity: O(n), for storing the lengths of palindromes and the best lengths at each index

class Solution {
  public:
    int maxSum(string &s) {
        int n = (int)s.size();
        if (n < 2) return 0;

        vector<int> rad(n); 
        for (int i = 0, L = 0, R = -1; i < n; ++i) {
            int k = (i > R) ? 1 : min(rad[L + R - i], R - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            rad[i] = k;
            if (i + k - 1 > R) { 
                L = i - k + 1;
                R = i + k - 1;
            }
        }

        vector<int> bestEnd(n, 0), bestStart(n, 0);
        for (int c = 0; c < n; ++c) {
            int len = 2 * rad[c] - 1;
            int l = c - rad[c] + 1;      
            int r = c + rad[c] - 1;
            bestEnd[r] = max(bestEnd[r] , len);
            bestStart[l] = max(bestStart[l] , len);
        }

        for (int i = n - 2; i >= 0; --i)
            bestEnd[i]   = max(bestEnd[i]  , bestEnd[i + 1] - 2);
            
        for (int i = 1; i < n; ++i)
            bestStart[i] = max(bestStart[i], bestStart[i - 1] - 2);

        int bestLeft = 0, ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            bestLeft = max(bestLeft, bestEnd[i]);
            ans  = max(ans, bestLeft + bestStart[i + 1]);
        }
        
        return ans;
    }
}; 