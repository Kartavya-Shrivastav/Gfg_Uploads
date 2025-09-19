#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string of parentheses, determine the minimum number of parentheses needed to make the string valid.
// Approach: Use two counters to track unmatched opening and closing parentheses while iterating through the string.

// Steps:
// 1. Initialize two counters: one for unmatched opening parentheses and one for unmatched closing parentheses.
// 2. Iterate through each character in the string. 
//    - If the character is '(', increment the opening counter.
//    - If the character is ')', check if there is an unmatched opening parenthesis.
//    - If there is, decrement the opening counter (to match the pair).
//    - If there isn't, increment the closing counter (indicating an unmatched closing parenthesis
// 3. The result is the sum of the two counters, representing the total unmatched parentheses.

// Time Complexity: O(n) where n is the length of the string.
// Space Complexity: O(1) as we are using only two counters.

class Solution {
  public:
    int minParentheses(string& s) {
        int open = 0;
        int close = 0;
        for(char cha : s){
            if(cha=='('){
                open++;
            } else if(cha ==')'){
                if(open>0){
                    open--;
                } else{
                    close++;
                }
            }
        }
        return open+close;
    }
};