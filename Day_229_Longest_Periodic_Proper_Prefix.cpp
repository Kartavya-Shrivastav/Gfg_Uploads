#include <bits/stdc++.h>
using namespace std;

// Problem: Find the longest prefix of a string that is also its suffix
// Approach: Use a two-pointer technique to compare characters from the start and end of the string

// Steps:
// 1. Initialize a pointer to the end of the string and another pointer to the start.
// 2. Compare characters from the end with those from the start.
// 3. If characters match, move both pointers inward.
// 4. If characters do not match, move the end pointer inward and reset the start pointer to the beginning of the string.
// 5. Continue until the end pointer reaches the beginning of the string.
// 6. Return the length of the longest prefix that matches the suffix.

// Time Complexity: O(n), where n is the length of the string (due to linear traversal)
// Space Complexity: O(1), as we are using only a few variables for pointers

class Solution {
  public:
    int getLongestPrefix(string &s) {
        int n = s.size();
        int len = s.size()-1;
        
        while(len){
            int sPtr = len;
            int i = 0;
            
            while(sPtr<n){
                if(s[sPtr] == s[i]){
                    i++;
                    sPtr++;
                }
                else{
                    break;
                }
            }
            
            if(sPtr==n)
              return len;
            
            len--;
        }
        
        return -1;
    }
};