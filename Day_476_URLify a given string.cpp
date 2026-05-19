#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string s, replace all spaces in the string with '%20' and return the resulting string.
Approach: We can count the number of spaces in the string to determine the new length of the string after replacement. Then, we can iterate through the string from the end and construct the new string in place.

Steps:
1. Count the number of spaces in the input string s.
2. Calculate the new length of the string after replacement, which is the original length plus 2 times the number of spaces (since '%20' has 3 characters and we are replacing 1 space).
3. Resize the string to the new length to accommodate the additional characters.
4. Use two pointers, one starting from the end of the original string and the other starting from the end of the new length.
5. Iterate backwards through the string:
   - If the current character is a space, replace it with '%20' in the new string.
   - If it's not a space, copy the character to the new position in the new string.
6. Return the modified string.

Time Complexity: O(n) - We need to iterate through the entire string once to count spaces and once to construct the new string, where n is the length of the original string.
Space Complexity: O(1) - We are modifying the string in place, so we are not using any additional space that grows with the input size.
*/

class Solution {
    int cntSpace(const string& s){
        int cnt=0;
        for(char c : s){
            if(c==' ')cnt++;
        }
        return cnt;
    }
public:
    string URLify(string &s) {
        // code here
        int len=s.length();
        int spaces=cntSpace(s);
        if(spaces==0)return s;
        int newLen=len+2*spaces;
        s.resize(newLen);
        int i=len-1;
        int j=newLen-1;
        while(i>=0){
            if(s[i]==' '){
                s[j--]='0';
                s[j--]='2';
                s[j--]='%';
            }else{
                s[j--]=s[i];
            }
            i--;
        }
        return s;
    }
};
