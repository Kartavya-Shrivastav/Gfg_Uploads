#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of palindromic substrings in a given string
// Approach: Use a two-pointer technique to expand around potential centers of palindromes

// Steps:
// 1. Iterate through each character in the string as a potential center of a palindrome.
// 2. For each character, check for both even-length and odd-length palindromes.
// 3. Use two pointers to expand outwards from the center, checking for matching characters
// 4. Count the number of palindromic substrings found during the expansion.
// 5. Return the total count of palindromic substrings.

// Time Complexity: O(n^2), where n is the length of the string (due to nested loops for expansion)
// Space Complexity: O(1), as we are using only a few variables for counting

class Solution {
  public:
    void checkPalindrome(string &s, int i, int j, int &cnt){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
            if(j-i > 2) cnt++;
        }
        
    }
    int countPS(string &s) {
        int cnt = 0;
        
        for(int i=0; i<s.length()-1; i++){
            checkPalindrome(s, i, i+1, cnt); 
            checkPalindrome(s, i, i, cnt); 
        }
        
        return cnt;
    }
};