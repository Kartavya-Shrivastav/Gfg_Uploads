#include <bits/stdc++.h>
using namespace std;

// Problem: Convert a Roman numeral to an integer
// Approach: Use a map to store the values of Roman numerals and iterate through the string to calculate the total value.

// Steps:
// 1. Create a map to store the values of each Roman numeral character.
// 2. Initialize a variable to hold the total value.
// 3. Iterate through the string, checking the value of the current character and the next character.
// 4. If the current character's value is less than the next character's value,
//    subtract the current character's value from the total; otherwise, add it.
// 5. Return the total value after processing all characters.

// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(1), since the map size is constant


class Solution {
  public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
            
        for (int i = 0; i < s.size(); ++i) {
            int curr = value[s[i]];
            int next = 0;
            if(i<s.size()-1){
                next = value[s[i+1]];
            }
    
            if (curr < next)
                ans -= curr;
            else
                ans += curr;
        }
    
        return ans;
    }
};