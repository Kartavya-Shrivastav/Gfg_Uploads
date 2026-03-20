#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string and an integer K, find the length of the longest substring that contains exactly K unique characters.
Approach: We can use a sliding window approach to solve this problem. We maintain a window defined by two pointers, `i` and `j`, which represent the start and end of the current substring. We also use a hash map to keep track of the frequency of characters in the current window. As we expand the window by moving the `i` pointer, we update the frequency of characters in the hash map. If the number of unique characters in the hash map exceeds K, we shrink the window from the left by moving the `j` pointer until we have at most K unique characters again. During this process, we keep track of the maximum length of a valid substring that contains exactly K unique characters.

Steps:
1. Initialize an unordered map `mp` to store the frequency of characters in the current window, and a variable `maxAns` to store the length of the longest valid substring, initialized to -1.
2. Initialize two pointers, `i` and `j`, to represent the end and start of the current window, respectively.
3. Iterate through the string using the `i` pointer:
    a. Increment the frequency of the current character `s[i]` in the map `mp`.
    b. If the size of the map (number of unique characters) is equal to K, calculate the length of the current window (which is `i - j + 1`) and update `maxAns` with the maximum of `maxAns` and the current window length.
    c. If the size of the map exceeds K, we need to shrink the window from the left:
        i. Decrement the frequency of the character at `s[j]` in the map.
        ii. If the frequency of that character becomes zero, remove it from the map.
        iii. Move the `j` pointer to the right to continue shrinking the window until we have at most K unique characters again.
4. After the loop, return the value of `maxAns` as the length of the longest substring that contains exactly K unique characters.

Time Complexity: O(n), where n is the length of the input string. We traverse the string once with the `i` pointer, and the `j` pointer also moves at most n times.
Space Complexity: O(k), as we are using a hash map to store the frequency of characters, and in the worst case, it can store up to K unique characters.
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        int maxAns=-1;

        int j=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        
            if(mp.size()==k){
                int len=i-j+1;
                maxAns=max(maxAns,len);
            }
        
            if(mp.size()>k){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
                
            }
        }
        return maxAns;
    }
    
};