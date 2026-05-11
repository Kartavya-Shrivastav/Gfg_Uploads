#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string s, remove all spaces from the string and return the resulting string.
Approach: We can iterate through the string and construct a new string that only includes the non-space characters.

Steps:
1. Initialize an empty string ans to store the result.
2. Iterate through each character in the input string s.
3. If the current character is not a space, append it to ans.   
4. After the loop, return ans.

Time Complexity: O(n) - We need to iterate through the entire string once, where n is the length of the string.
Space Complexity: O(n) - In the worst case, if there are no spaces, we will create a new string that is the same length as the input string.
*/

class Solution {
  public:
    string removeSpaces(string& s) {
        string ans="";
       
       for(int i =0; i< s.length(); i++){
           if(s[i] != ' '){
               ans+= s[i];
           }
       }
       return ans;
    }
};