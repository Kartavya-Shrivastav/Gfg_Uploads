#include <bits/stdc++.h>
using namespace std;

// Problem: Case-specific Sorting of Strings
// Approach: Sort uppercase and lowercase characters separately

// Steps:
// 1. Create a copy of the string and sort it.
// 2. Iterate through the original string and replace uppercase characters with sorted uppercase characters.
// 3. Iterate through the original string again and replace lowercase characters with sorted lowercase characters.
// 4. Return the modified string.
// 5. Return the flattened list starting from the dummy's bottom pointer

// Time Complexity: O(N log N) where N is the length of the string
// Space Complexity: O(N) for the sorted copy of the string

class Solution {
  public:
    string caseSort(string& s) {
        // code here
         string p = s;
        sort(p.begin(), p.end());
        int i = 0;
        for(auto& ch : s){
            if(isupper(ch)){
                ch = p[i++];
            }
        }
        for(auto& ch : s){
            if(islower(ch)){
                ch = p[i++];
            }
        }
        return s;
    }
};