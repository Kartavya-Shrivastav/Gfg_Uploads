#include <bits/stdc++.h>
using namespace std;

// Problem: Given two strings, pattern and target, determine if the pattern can be formed from the target by deleting some characters. If a character in the target is deleted, the next character must also be deleted (i.e., deletions must occur in pairs).
// Approach: Use two pointers to traverse both strings from the end. Maintain a count of deletions to ensure they occur in pairs. If characters match, move both pointers; if they don't, increment the deletion count and move the target pointer. If the deletion count is odd, skip the next character in the target. The pattern can be formed if we reach the beginning of the pattern string.

// Steps:
// 1. Initialize two pointers, i and j, to the end of the pattern and target strings, respectively.
// 2. Initialize a count variable to track the number of deletions.
// 3. While both pointers are valid:
//    a. If the characters at both pointers match:
//       - If the count of deletions is even, move both pointers back.
//       - If the count is odd, move the pattern pointer back and increment the count.
//    b. If the characters do not match:
//       - Move the pattern pointer back and increment the count.
// 4. After the loop, if the target pointer has moved past the beginning of the string, return true; otherwise, return false.
// 5. The function returns true if the pattern can be formed from the target, otherwise false.

// Time Complexity: O(n + m), where n and m are the lengths of the pattern and target strings, respectively.
// Space Complexity: O(1), as we are using a constant amount of extra space.


class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
         int n= pat.size();
              int m= tar.size();
              int i=n-1;
              int j=m-1;
              int count =0;
              while (i>=0 && j>=0){
                      if (pat[i]==tar[j]){
                            if (count%2==0) {
                                j--;
                                count=0;
                                i--;
                            }
                            else{
                                 i--;
                                 count++;
                         
                            }
                      }
                      else{
                           i--; 
                           count++;
                      }
              }

              if (j<0) return true;
              else return false;
    }
};