#include <bits/stdc++.h>
using namespace std;

// Problem: Check if a given sentence is a palindrome
// Approach: Normalize the string by removing non-alphanumeric characters and converting to lowercase, then check if it reads the 
//           same forwards and backwards.

// Steps:
// 1. Iterate through the string and build a new string containing only alphanumeric characters in lowercase.
// 2. Use two pointers, one starting from the beginning and the other from the end of the normalized string.
// 3. Compare characters at both pointers, moving towards the center.
// 4. If all characters match, the sentence is a palindrome; otherwise, it is not.
// 5. Return true if it is a palindrome, false otherwise.


// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(n), for the normalized string

class Solution {
  public:
    bool isPalinSent(string &s) {
        string check;

        for (char ch : s)
            if (isalnum(ch)) check += tolower(ch);
        
        
        int l = 0, r = check.size() - 1;
        while (l < r)
            if (check[l++] != check[r--]) return false;
        

        return true;
    }
};