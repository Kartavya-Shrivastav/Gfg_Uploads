#include <bits.stdc++.h>
using namespace std;

// Problem Statement: Validate an IP address
// Approach: Check if the string representation of the IP address meets the criteria for a valid IPv4 address

// Steps:
// 1. Split the string by '.' to get the four octets.
// 2. Check if there are exactly four octets.
// 3. Validate each octet:
//    - It should be a number between 0 and 255.
//    - It should not have leading zeros unless it is '0'.
// 4. Return 1 if valid, otherwise return 0.

// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(1), as we are using a constant amount of space for validation.

class Solution {
  public:
    int isValid(string &s) {
        string t="";
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(i>0&&s[i]==s[i-1]&&s[i]=='.')return 0;
            else if(s[i]=='.')
            {
                cnt++;
                if(cnt>3)return 0;
                if(stoi(t)>255)return 0;
                if(stoi(t)!=0&&t[0]=='0')return 0;
                t="";
            }
            else t+=s[i];
        }
        if(stoi(t)>255)return 0;
        if(stoi(t)!=0&&t[0]=='0')return 0;
        return cnt==3;
    }
};