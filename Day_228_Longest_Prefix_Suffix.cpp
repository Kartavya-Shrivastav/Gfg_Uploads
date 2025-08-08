#include <bits/stdc++.h>
using namespace std;

// Problem: Find the length of the longest prefix which is also a suffix in a given string
// Approach: Iterate through the string to find the first character, then check for matching characters in the suffix starting from 
//           each occurrence of that character.

// Steps:
// 1. Identify the first character of the string.
// 2. Store the indices of all occurrences of this character in a vector.
// 3. For each index, check if the substring starting from that index matches the prefix of the string.
// 4. If a match is found, calculate the length of the matching suffix.
// 5. Return the length of the longest matching suffix found.

// Time Complexity: O(n^2), where n is the length of the string (due to nested loops)
// Space Complexity: O(n), for storing indices of occurrences of the first character
// Note: This solution is not optimal for large strings; a more efficient approach would be to

class Solution {
  public:
    int getLPSLength(string &s) {
        char ch = s[0];
        int n = s.length();
        vector<int>idx;
        for (int i=1; i<n; i++){
            if (s[i] == ch) idx.push_back(i);
        }
        
        for (int i=0; i<idx.size(); i++){
            int j = 0, t = idx[i];
            int ok = true;
            while (t < n){
                if (s[j] == s[t]){
                    j+=1;
                    t+=1;
                }
                else {
                    ok = false;
                    break;
                }
            }
            if (ok) return n - idx[i];
        }
        return 0;
    }
};