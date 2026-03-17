#include <bits/stdc++.h>    
using namespace std;

/*
Problem: Given two strings s1 and s2, determine if they are isomorphic. Two strings are isomorphic if the characters in s1 can be replaced to get s2, while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Approach: We can use two arrays to keep track of the mapping of characters from s1 to s2 and vice versa. We will iterate through both strings simultaneously and check the mapping for each character. If we find a mismatch in the mapping, we can conclude that the strings are not isomorphic.

Steps:
1. Initialize two arrays, f1 and f2, of size 26 (for lowercase letters) to keep track of the mapping from s1 to s2 and from s2 to s1, respectively. Set all values in f1 to -1 and all values in f2 to 0.
2. Iterate through both strings simultaneously: 
    - For each character in s1 and s2, check if there is an existing mapping in f1 for the character from s1 and in f2 for the character from s2.
    - If there is no existing mapping (f1[s1[i] - 'a'] == -1 and f2[s2[i] - 'a'] == 0), create a new mapping by setting f1[s1[i] - 'a'] to the index of the character in s2 and marking f2[s2[i] - 'a'] as used.
    - If there is an existing mapping, check if it matches the current characters. If it does not match, return false.
3. If we successfully iterate through both strings without finding any mismatches, return true.

Time Complexity: O(n), where n is the length of the input strings.
Space Complexity: O(1), since we are using fixed-size arrays for character mapping.
*/

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        int n = s1.length();
        vector<int> f1(26, -1), f2(26, 0);
        for(int i = 0; i < n; i++) {
            if(f1[s1[i] - 'a'] == -1 && f2[s2[i] - 'a'] == 0) f1[s1[i] - 'a'] = (s2[i] - 'a');
            else if(f1[s1[i] - 'a'] != s2[i] - 'a') return false;
            f2[s2[i] -'a'] = 1;
        }
        return true;
    }
};