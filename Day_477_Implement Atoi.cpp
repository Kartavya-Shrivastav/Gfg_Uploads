#include <bits/stdc++.h>
using namespace std;

/*
Problem: Implement the function myAtoi which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
Approach: We can follow these steps to implement the function:
1. Ignore leading whitespace characters.
2. Check for an optional sign character ('+' or '-').
3. Convert the subsequent characters to an integer until a non-digit character is encountered or the end of the string is reached.
4. Handle overflow and underflow cases by returning INT_MAX or INT_MIN when the result exceeds the limits of a 32-bit signed integer.

Steps:
1. Initialize variables to store the sign (default is positive), the result (initially 0), and an index to traverse the string.
2. Skip leading whitespace characters by incrementing the index until a non-whitespace character is found.
3. Check for an optional sign character. If a '-' is found, set the sign to negative. If a '+' is found, keep the sign as positive. Increment the index to move past the sign character.
4. Iterate through the characters of the string starting from the current index:
   - If the current character is a digit, convert it to an integer and update the result. Check for overflow and underflow conditions before updating the result.
   - If a non-digit character is encountered, break the loop.   
5. Return the final result multiplied by the sign.

Time Complexity: O(n) - We need to iterate through the string at most once, where n is the length of the string.
Space Complexity: O(1) - We are using a constant amount of space to store the sign, result, and index variables.
*/

class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign = 1, r = 0, i = 0;
        while(s[i] == ' ') i++;        // ignore whitespaces
        if(s[i] == '-' || s[i] == '+'){
            if(s[i++] == '-')       sign = -1;
        }

        while(s[i] >= '0' && s[i] <= '9'){ 
            if(r > INT_MAX/10 || r == INT_MAX/10 && s[i]-'0' > 7)     
                return      sign == 1 ? INT_MAX : INT_MIN;
            r = 10*r+(s[i++]-'0');
        }

        return  r*sign;
    }
};