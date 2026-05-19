#include <bits/stdc++.h>
using namespace std;

/*
Problem: 266. Palindrome Permutation
Given a string s, return true if a permutation of the string could form a palindrome. A palindrome is a word or phrase that reads the same backward as forward, ignoring spaces, punctuation, and capitalization.

Approach: To determine if a permutation of the string can form a palindrome, we need to check the frequency of each character in the string. For a string to be able to form a palindrome, at most one character can have an odd frequency (this would be the middle character in an odd-length palindrome).

Steps:
1. Initialize a variable `track` to 0. This variable will be used to track the frequency of characters using bit manipulation.
2. Iterate through each character `c` in the string `s`:
    - Update `track` by XORing it with `1 << (c - 'a')`. This will toggle the bit corresponding to the character `c`.
3. After processing all characters, count the number of set bits in `track` using `__builtin_popcount(track)`. This will give us the number of characters that have an odd frequency.
4. If the number of set bits is greater than 1, return false (since more than one character has an odd frequency). Otherwise, return true (the string can form a palindrome).

Time complexity of this approach is O(n), where n is the length of the string, and the space complexity is O(1) since we are using a fixed amount of space for the `track` variable.
Space complexity is O(1) because we are using a fixed amount of space for the `track` variable, regardless of the input size.
*/

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        int track = 0;
        for(char c: s){
            track = track^(1<<(c-'a'));
        }
        int set_bits = __builtin_popcount(track);
        if(set_bits>1)return false;
        return true;
    }
};