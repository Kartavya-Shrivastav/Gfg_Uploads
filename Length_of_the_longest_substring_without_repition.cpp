#include <bits/stdc++.h>
using namespace std;

// Problem: Length of the Longest Substring Without Repetition
// Approach: Use a sliding window technique with two pointers to track the longest substring without repeating characters

// Steps:
// 1. Initialize two pointers, left and right, both starting at the beginning of the string.
// 2. Use a frequency array to keep track of character counts in the current window.
// 3. Expand the right pointer to include new characters until a duplicate is found.
// 4. If a duplicate is found, move the left pointer to the right until the duplicate is removed from the window.
// 5. Update the maximum length of the substring found so far.

// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(1), as we are using a fixed-size frequency array for lowercase English letters.
// Note: The string is assumed to contain only lowercase English letters.

class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        int n = s.length();
        int l=0;
        int mx=0;
        vector<int>frq(26,0);
        
        for(int r=0; r<n;r++){  
            frq[s[r]-'a']++;
            while(frq[s[r]-'a']>1){
                frq[s[l]-'a']--;
                l++;
            }
            
            mx  = max(mx, r-l+1);
        }
        return mx;
    }
};