#include <bits/stdc++.h>
using namespace std;

// Problem: Check if Frequencies Can Be Equal
// Approach: Frequency Count and Set Comparison 

// Steps:
// 1. Count the frequency of each character in the string.  
// 2. Store the frequencies in a vector.
// 3. Use a set to track unique frequencies.
// 4. If the set size is more than 2, return false.
// 5. Check the conditions for equal frequencies:
//    - If all characters have the same frequency (mx == mn).
//    - If one character has a frequency of 1 and it appears only once (mn == 1 && freq[mn] == 1).
//    - If one character has a frequency of mx and it appears only once, and the
//      difference between mx and mn is 1 (freq[mx] == 1 && mx - mn == 1).

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since the frequency count is limited to 26 characters.

class Solution {
  public:
    // Function to check if frequencies of all characters can be made equal by removing at most one character
    bool sameFreq(string& s) {
        vector<int> mp(26, 0); // Frequency array for 26 lowercase letters
        for(char ch : s) 
            mp[ch - 'a']++; // Count frequency of each character

        unordered_set<int> ss; // To store unique frequencies
        int mx = 0, mn = 100000; // Initialize max and min frequency
        unordered_map<int, int> freq; // Map to count occurrences of each frequency

        // Iterate over all possible characters
        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i] != 0) { // If character is present in string
                ss.insert(mp[i]); // Add frequency to set
                freq[mp[i]]++; // Count how many times this frequency occurs
                mx = max(mx, mp[i]); // Update max frequency
                mn = min(mn, mp[i]); // Update min frequency
            }
        }

        // If more than 2 unique frequencies, cannot make all equal by removing one character
        if(ss.size() > 2) return false;

        // Check if all frequencies are already equal,
        // or if one character can be removed to make all frequencies equal
        if((mx == mn) || (mn == 1 && freq[mn] == 1) || (freq[mx] == 1 && mx - mn == 1)) 
            return true;

        return false;
    }
};